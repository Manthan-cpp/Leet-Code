class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), order(n);
        int timer = 0;

        vector<pair<int, int>> st;
        st.push_back({0, -1});

        while (!st.empty()) {
            auto [u, p] = st.back();
            st.pop_back();

            if (u >= 0) {
                tin[u] = timer;
                order[timer++] = u;
                up[0][u] = (p == -1 ? u : p);

                for (int k = 1; k < LOG; k++)
                    up[k][u] = up[k - 1][up[k - 1][u]];

                st.push_back({~u, p});

                for (int v : adj[u]) {
                    if (v == p) continue;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, u});
                }
            } else {
                tout[~u] = timer - 1;
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        vector<int> bit(n + 2);

        auto add = [&](int idx, int val) {
            for (idx++; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto sum = [&](int idx) {
            int res = 0;
            for (idx++; idx > 0; idx -= idx & -idx)
                res ^= bit[idx];
            return res;
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            if (r + 1 < n) add(r + 1, val);
        };

        vector<int> mask(n);

        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            rangeUpdate(tin[i], tout[i], mask[i]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            string third;
            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];
                int newMask = 1 << (c - 'a');
                int diff = mask[u] ^ newMask;

                rangeUpdate(tin[u], tout[u], diff);
                mask[u] = newMask;
                s[u] = c;
            } else {
                int v = stoi(third);
                int w = lca(u, v);

                int pathMask = sum(tin[u]) ^ sum(tin[v]) ^ mask[w];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};