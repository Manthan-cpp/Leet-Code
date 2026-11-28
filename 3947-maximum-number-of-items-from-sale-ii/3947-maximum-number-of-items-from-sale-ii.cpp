
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0;

        for (auto& item : items) {
            mx = max(mx, item[0]);
        }

        vector<int> freq(mx + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> gain(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            int total = 0;

            for (int j = i; j <= mx; j += i) {
                total += freq[j];
            }

            gain[i] = total - 1;
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long minPrice = items[0][1];
        long long ans = 0;
        long long remaining = budget;

        for (auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            if (price >= 2 * minPrice) {
                break;
            }

            long long take = min(
                (long long)gain[factor],
                remaining / price
            );

            ans += 2 * take;
            remaining -= take * price;
        }

        ans += remaining / minPrice;

        return ans;
    }
};
