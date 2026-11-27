
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeItems = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeItems++;
                }
            }

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + 1 + freeItems);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }

        return ans;
    }
};
