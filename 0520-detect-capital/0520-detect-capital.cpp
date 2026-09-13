class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper = 0;

        for (char c : word) {
            if (isupper(c))
                upper++;
        }

        if (upper == 0 || upper == n)
            return true;

        return upper == 1 && isupper(word[0]);
    }
};