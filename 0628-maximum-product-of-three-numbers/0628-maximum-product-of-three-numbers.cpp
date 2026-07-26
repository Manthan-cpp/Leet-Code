class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size(),i=0,j=i+1,k=j+1;
        if(n==3){
            return nums[i]*nums[j]*nums[k];
        }
        sort(nums.begin(),nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    }
};