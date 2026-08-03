class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int l = s.length(), i = 0, digit = 0;
        long long ans = 0;
        while (i < l && s[i] == ' ')
            i++;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                neg = true;
            }
            i++;
        }
        for (; i < l; i++) {
            char c = s[i];
            if (c > '9' || c < '0') {
                break;
            }
            int d=c-'0';
            if (ans > INT_MAX / 10 ||
            (ans == INT_MAX / 10 && d > INT_MAX % 10)){
                if(neg)return INT_MIN;
                else return INT_MAX;
            }
            ans = ans * 10 + d;
        }
        if (neg) {
            return -ans;
        }
        return ans;
    }
};