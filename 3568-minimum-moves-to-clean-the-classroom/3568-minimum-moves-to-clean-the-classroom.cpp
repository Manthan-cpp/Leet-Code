class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = 0, sc = 0, cnt = 0;
        int id[20][20];
        memset(id, -1, sizeof(id));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S')
                    sr = i, sc = j;
                else if (classroom[i][j] == 'L')
                    id[i][j] = cnt++;
            }
        }
        if (cnt == 0)
            return 0;
        int total = 1 << cnt;
        vector<int> best(m * n * total, -1);
        auto idx = [&](int r, int c, int mask) {
            return ((r * n + c) * total + mask);
        };
        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});
        best[idx(sr, sc, 0)] = energy;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int full = total - 1, moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();
                if (mask == full)
                    return moves;
                if (e == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;
                    int ne = e - 1, nmask = mask;
                    if (classroom[nr][nc] == 'R')
                        ne = energy;
                    if (classroom[nr][nc] == 'L')
                        nmask |= 1 << id[nr][nc];
                    int pos = idx(nr, nc, nmask);
                    if (ne <= best[pos])
                        continue;
                    best[pos] = ne;
                    q.push({nr, nc, ne, nmask});
                }
            }
            moves++;
        }
        return -1;
    }
};