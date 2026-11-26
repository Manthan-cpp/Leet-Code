class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool alice = true;

        while (n >= stones) {
            n -= stones;
            stones--;
            alice = !alice;
        }

        return !alice;
    }
};