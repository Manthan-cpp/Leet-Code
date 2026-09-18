class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, n), r(26, -1);

        for (int i = 0; i < n; i++) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> v;

        for (int c = 0; c < 26; c++) {
            if (r[c] == -1) continue;

            int left = l[c], right = r[c];
            bool ok = true;

            for (int i = left; i <= right; i++) {
                int x = s[i] - 'a';

                if (l[x] < left) {
                    ok = false;
                    break;
                }

                right = max(right, r[x]);
            }

            if (ok) v.push_back({left, right});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        int end = -1;

        for (auto &[left, right] : v) {
            if (left > end) {
                ans.push_back(s.substr(left, right - left + 1));
                end = right;
            }
        }

        return ans;
    }
};