class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n, sum = 0, product = 1;
        while (x > 0) {
            int digit = x % 10;
            sum += digit;
            product *= digit;
            x /= 10;
        }
        return n % (sum + product) == 0;
    }
};