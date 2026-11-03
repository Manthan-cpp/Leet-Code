class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=n-nums[i];
        }
        return ans;
    }
};