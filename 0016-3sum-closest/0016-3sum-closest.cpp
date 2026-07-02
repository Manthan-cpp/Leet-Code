#include <algorithm>
#include <limits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i, j, k, sum;
        int closest = nums[0]+nums[1]+nums[2];
        for (i = 0; i < n-2; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum)<abs(target-closest)){
                    closest=sum;
                }
                if(sum<target){
                j++;
                }
                else if(sum>target){
                k--;
                }
                else if(sum==target){
                    return sum;
                    break;
                }
            }
        }
        return closest;        
    }
};