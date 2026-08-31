class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,int idx){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=idx;j<nums.size();j++){
            swap(nums[idx],nums[j]);
            solve(nums,ans,idx+1);
            swap(nums[idx],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int idx=0;
        solve(nums,ans,idx);
        return ans;
    }
};