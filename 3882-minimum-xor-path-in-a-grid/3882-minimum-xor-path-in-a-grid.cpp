class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> dp(n, vector<bool>(1024, false));

        for (int i = 0; i < m; i++) {
            vector<vector<bool>> curr(n, vector<bool>(1024, false));

            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j][grid[i][j]] = true;
                    continue;
                }

                for (int x = 0; x < 1024; x++) {
                    if (j > 0 && curr[j - 1][x])
                        curr[j][x ^ grid[i][j]] = true;

                    if (i > 0 && dp[j][x])
                        curr[j][x ^ grid[i][j]] = true;
                }
            }

            dp = curr;
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return 0;
    }
};