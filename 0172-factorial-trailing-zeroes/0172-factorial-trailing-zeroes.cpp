class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n){
            n=n/5;
            cnt=cnt+n;
        }
        return cnt;
    }
};