class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), farth = 0;
        for(int i=0;i<n;i++){
            if(i>farth)
            return false;
            farth=max(farth,i+nums[i]);
        }
        return true;
    }
};