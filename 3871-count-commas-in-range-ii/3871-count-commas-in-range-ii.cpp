class Solution {
public:
    long long countCommas(long long n) {
        long long start=1000;
        long long result=0;
        while(start <=n){
            result+=(n-start+1);
            start*=1000;
        }
        return result;
    }
};