#include <algorithm>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(),i=0,s=0,e=n-1,p=n-1,mid=0;
        for(i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                p=i;
                break;
            }
        }
        if(target<nums[0]){
            s=p+1;
        }
        else{
            e=p;
        }
        while(s<=e){
            mid=(s+e)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
        
    }
};