class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minElidx=min_element(nums.begin(),nums.end())-nums.begin();
        int maxElidx=max_element(nums.begin(),nums.end())-nums.begin();
        int left=min(minElidx,maxElidx);
        int right=max(minElidx,maxElidx);
        return min({left+1+n-right,right+1,n-left});
    }
};