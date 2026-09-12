class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            return x[0] < y[0];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<vector<Node>> dp(n + 1, vector<Node>(5, {-1, {}}));

        dp[0][0] = {0, {}};

        for (int i = 1; i <= n; i++) {
            long long l = a[i - 1][0];
            long long weight = a[i - 1][2];
            int idx = a[i - 1][3];

            int prev = lower_bound(ends.begin(), ends.end(), l) - ends.begin();

            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];

                if (k > 0 && dp[prev][k - 1].score != -1) {
                    Node candidate = dp[prev][k - 1];
                    candidate.score += weight;
                    candidate.indices.push_back(idx);

                    sort(candidate.indices.begin(), candidate.indices.end());

                    if (better(candidate, dp[i][k]))
                        dp[i][k] = candidate;
                }
            }
        }

        Node ans = dp[n][0];

        for (int k = 1; k <= 4; k++) {
            if (better(dp[n][k], ans))
                ans = dp[n][k];
        }

        return ans.indices;
    }
};