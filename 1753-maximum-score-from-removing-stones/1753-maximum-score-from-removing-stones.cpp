class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m = max(max(a, b), c);
        if (2*m > a+b+c) return a+b+c - m;
        return (a+b+c)/2;
    }
};