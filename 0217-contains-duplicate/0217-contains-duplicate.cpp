class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int m=nums.size();
        sort(begin(nums),end(nums));
        if(m==1){
            return false;
        }
        for(int i=0;i<m-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};