class Solution {
public:
    int integerBreak(int n) {
        int a , b=1;
        if(n==1 || n==2){
            return 1;
        }
        if(n==3)return 2;
        if(n%3==0){
            a=n/3;
            for(int i=0;i<a;i++){
                b*=3;
            }
        }
        else if(n%3==1){
            a=(n-3)/3;
            for(int i = 0;i<a;i++){
                b*=3;
            }
            b*=4;
        }
        else{
            a=(n-2)/3;
            for(int i=0;i<a;i++){
                b*=3;
            }
            b*=2;
        }
        return b;
    }
};