
class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int x = sqrt(total);

        return (x * x == total) ? x : -1;
    }
};
