class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), total = m * n;
        vector<vector<int>> ans(m, vector<int>(n));
        k %= total;
        if (k % (total) == 0) {
            return grid;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int oldind = i * n + j;
                int newind = (oldind + k) % total;
                int newrow = newind / n;
                int newcol = newind % n;
                ans[newrow][newcol]=grid[i][j];
            }
        }
        return ans;
    }
};