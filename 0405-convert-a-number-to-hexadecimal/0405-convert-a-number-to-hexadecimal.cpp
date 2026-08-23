class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string s = "0123456789abcdef", ans;
        unsigned int n = num;
        while (n) {
            ans += s[n & 15];
            n >>= 4;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};