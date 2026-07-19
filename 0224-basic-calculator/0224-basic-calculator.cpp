class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long ans = 0;
        long long num = 0;
        long long sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if (c == ')') {
                ans += sign * num;
                num = 0;

                ans *= st.top();
                st.pop();

                ans += st.top();
                st.pop();
            }
        }

        ans += sign * num;
        return (int)ans;
    }
};