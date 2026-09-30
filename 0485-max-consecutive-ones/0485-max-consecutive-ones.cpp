class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=0,ones=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
            else{
                mx=max(mx,ones);
                ones=0;
            }
        }
        mx=max(mx,ones);
        return mx;
    }
};