#include <algorithm>
#include <limits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> a;
        int i, j, k, sum, diff , min=INT_MAX, index=0;
        for (i = 0; i < n-2; i++) {
            j = i + 1;
            k = n - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                a.push_back(sum);
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
        for(int i=0;i<a.size();i++){
            diff=abs(target-a[i]);
            if(diff<min){
                min=diff;
                index = i;
            }
        }
        return a[index];
    }
};