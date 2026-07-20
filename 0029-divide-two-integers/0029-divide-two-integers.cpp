class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }
        bool sign = true;
        if (dividend >= 0 && divisor < 0) {
            sign= false;
        } else if (dividend <= 0 && divisor > 0) {
            sign =false;
        }
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        divisor = abs((long long)divisor);
        long long q = 0;
        while (n >= d) {
            int c = 0;
            while (n >= (d << c + 1)) {
                c++;
            }
            q += 1LL << c;
            n -= d << c;
        }
        if (q == 1LL << 31 && sign) {
            return INT_MAX;
        } else if (q == 1LL << 31 && !sign) {
            return INT_MIN;
        }
        return sign ? q : -q;
    }
};