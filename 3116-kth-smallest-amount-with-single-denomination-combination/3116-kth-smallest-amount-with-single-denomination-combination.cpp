class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long lo = 1, hi = 1LL * *min_element(coins.begin(), coins.end()) * k;

        auto lcm = [](long long a, long long b) {
            return a / gcd(a, b) * b;
        };

        auto count = [&](long long x) {
            long long res = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                long long v = 1;
                int bits = 0;

                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        ++bits;
                        v = lcm(v, coins[i]);
                        if (v > x) break;
                    }
                }

                if (v > x) continue;

                if (bits & 1) res += x / v;
                else res -= x / v;
            }

            return res;
        };

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};