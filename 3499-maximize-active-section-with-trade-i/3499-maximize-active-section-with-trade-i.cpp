class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        s = '1' + s + '1';
        int n = s.length();
        int cnt = 0, gain, leftz, rightz, maxtrade = 0;
        vector<pair<char, int>> grps;
        for (int i = 0; i < n; i++) {
            cnt = 1;
            char c = s[i];
            while (i < n - 1 && c == s[i + 1]) {
                cnt++;
                i++;
            }
            grps.push_back({c, cnt});
        }
        for (int i = 1; i < grps.size() - 1; i++) {
            if (grps[i].first == '1') {
                if (grps[i - 1].first == '0' && grps[i + 1].first == '0') {
                    leftz = grps[i - 1].second;
                    rightz = grps[i + 1].second;
                    gain = leftz + rightz;
                    maxtrade = max(maxtrade, gain);
                }
            }
        }
        return ones + maxtrade;
    }
};