class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2;
        vector<int> cnt(26);
        for(char c : s) cnt[c-'a']++;
        int odd = 0, mid = -1;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd++;
                mid = i;
            }
        }
        if(odd > 1) return "";
        for(int i = 0; i < 26; i++) cnt[i] /= 2;

        string half;

        auto build = [&](string h) {
            string res = h;
            if(n % 2) res += char('a' + mid);
            reverse(h.begin(), h.end());
            res += h;
            return res;
        };

        function<string(int)> dfs = [&](int pos) -> string {
            if(pos == m) {
                string res = build(half);
                return res > target ? res : "";
            }

            for(int c = 0; c < 26; c++) {
                if(cnt[c] == 0) continue;
                if(c < target[pos]-'a') continue;

                cnt[c]--;
                half.push_back('a' + c);

                if(c > target[pos]-'a') {
                    string h = half;
                    for(int x = 0; x < 26; x++)
                        h += string(cnt[x], 'a' + x);
                    string res = build(h);
                    half.pop_back();
                    cnt[c]++;
                    return res > target ? res : "";
                }

                string res = dfs(pos + 1);
                half.pop_back();
                cnt[c]++;

                if(!res.empty()) return res;
            }

            return "";
        };

        return dfs(0);
    }
};