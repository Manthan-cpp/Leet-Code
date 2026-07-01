#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i + 1, k = n - 1;
        vector<vector<int>> b;
        sort(nums.begin(), nums.end());
        for (i = 0; i < n; i++) {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            j = i + 1;
            k = n - 1;
            while (j< k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    b.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                    while(k>j && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
                
            }
            
        }
        return b;
    }
};
