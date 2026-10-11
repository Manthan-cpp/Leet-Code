class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n=nums.size(),sum=0,c=1;
        for(int a:nums){
            if(n%c==0){
                sum+=a*a;
            }
            c++;
        }
        return sum;
    }
};