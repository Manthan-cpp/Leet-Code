class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(), push = 0;
        if (n <= 8)
            push = n;
        else if (n > 8 && n <= 16)
            push = 8 + (n - 8) * 2;
        else if (n > 16 && n <= 24)
            push = 24 + (n - 16) * 3;
        else
            push = 48 + (n - 24) * 4;
        return push;
    }
};