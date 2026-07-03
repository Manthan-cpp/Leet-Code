class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n, 0);

        int mx = 0;
        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            mx = max(mx, e[2]);
        }

        queue<int> q;
        vector<int> topo;
        vector<int> deg = indegree;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &[v, w] : graph[u]) {
                if (--deg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) -> bool {
            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                for (auto &[v, w] : graph[u]) {
                    if (w < limit) continue;
                    if (v != n - 1 && !online[v]) continue;
                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0, hi = mx;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }

        return check(lo) ? lo : -1;
    }
};