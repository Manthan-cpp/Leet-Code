class Solution {
public:
    int flipLights(int n, int presses) {
        n = min(n, 3);

        if (presses == 0)
            return 1;

        if (presses == 1) {
            if (n == 1) return 2;
            if (n == 2) return 3;
            return 4;
        }

        if (presses == 2) {
            if (n == 1) return 2;
            if (n == 2) return 4;
            return 7;
        }

        if (n == 1) return 2;
        if (n == 2) return 4;
        return 8;
    }
};