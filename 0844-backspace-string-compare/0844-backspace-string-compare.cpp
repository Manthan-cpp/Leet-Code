class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        int skip = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skip++;
                    i--;
                } else if (skip > 0) {
                    i--;
                    skip--;
                } else {
                    break;
                }
            }
            skip = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    skip++;
                    j--;
                } else if (skip > 0) {
                    j--;
                    skip--;
                } else {
                    break;
                }
            }
            if (i<0 ||j<0) {
                return i==j;
            } else if(s[i]!=t[j]){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};