class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,true);
        int c=0,j=2;
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                c++;
                for(j=2*i;j<n;j=j+i){
                    prime[j]=0;
                }
            }
        }
        return c;
    }
};