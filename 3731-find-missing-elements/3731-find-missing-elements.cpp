class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size(),i=nums[0];
        vector<int>ans;
        int j=0;
        while(i<nums[n-1] && j<n){
            if(i==nums[j]){
                i++;
                j++;
            }
            else{
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};