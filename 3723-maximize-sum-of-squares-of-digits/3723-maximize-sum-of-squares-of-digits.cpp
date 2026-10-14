class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (num--) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};