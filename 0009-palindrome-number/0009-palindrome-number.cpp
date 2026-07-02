class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long n=0;
        int r=0,x1=x;
        while(x!=0){
        r=x%10;
        n=(n*10)+r;
        x=x/10;
        }
        if(n==x1){
            return true;
        }
        else{
            return false;
        }
        
    }
};