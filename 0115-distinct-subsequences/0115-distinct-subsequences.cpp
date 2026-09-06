class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        vector<long long> dp(n + 1);
        dp[0] = 1;

        for (char c : s) {
            for (int j = n; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] = min(dp[j] + dp[j - 1], (long long)INT_MAX);
                }
            }
        }

        return (int)dp[n];
    }
};