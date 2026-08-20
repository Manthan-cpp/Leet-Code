class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        // if(n==1)return true;
        int i;
        while(n%3==0){
            n=n/3;
        }
        if(n==1)return true;
        return false;
    }
};