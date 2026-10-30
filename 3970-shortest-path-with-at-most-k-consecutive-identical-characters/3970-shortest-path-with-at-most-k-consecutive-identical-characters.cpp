
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt]) continue;

            if(u == n - 1) return d;

            for(auto [v, w] : adj[u]) {
                int newCnt;

                if(labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                } 
                else {
                    newCnt = 1;
                }

                if(newCnt > k) continue;

                long long newDist = d + w;

                if(newDist < dist[v][newCnt]) {
                    dist[v][newCnt] = newDist;
                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};
