class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0,c=0;
        bool nonZ=false;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]!=0){
                nonZ=true;
            }
        }
        if(x!=0){
            return n;
        }
        if(nonZ){
            return n-1; 
        }
        return 0;
    }
};