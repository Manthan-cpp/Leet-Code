class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0),dp(k,0);
        
        for(int num:nums){
            vector<long long> ndp(k,0);
            int rem=num%k;
            
            ndp[rem]++;
            
            for(int r=0;r<k;r++){
                ndp[(r*rem)%k]+=dp[r];
            }
            
            for(int r=0;r<k;r++){
                ans[r]+=ndp[r];
            }
            
            dp=ndp;
        }
        
        return ans;
    }
};