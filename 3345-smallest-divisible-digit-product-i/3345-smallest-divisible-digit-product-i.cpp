class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int digit=n , prod=1;
        while(digit!=0){
            int r=digit%10;
            digit/=10;
            prod*=r;       
        }
        if(prod%t==0){
            break;
        }
        n++;
        }
        return n;
    }
};