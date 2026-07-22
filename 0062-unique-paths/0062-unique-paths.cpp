class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int N = m + n - 2;
        int R = min(m - 1, n - 1);

        for (int i = 1; i <= R; i++) {
            ans = ans * (N - R + i) / i;
        }

        return (int)ans;
    }
};