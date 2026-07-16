class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for (long long i = 1; i <= n; i *= 10) {
            long long high = n / (i * 10);
            long long cur = (n / i) % 10;
            long long low = n % i;

            if (cur == 0)
                ans += high * i;
            else if (cur == 1)
                ans += high * i + low + 1;
            else
                ans += (high + 1) * i;
        }

        return ans;
    }
};