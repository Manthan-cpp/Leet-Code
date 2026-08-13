class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        if(n%2!=0 || n<=0)
            return false;
       

        for(long long i=2;i<=n;i*=2){
            if(i==n){
                return true;
            }
        }
        return false;
    }
};