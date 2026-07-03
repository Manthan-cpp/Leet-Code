#include <algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                long long l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    } else if (sum > target)
                        r--;
                    else if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        r--;
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (r > l && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return result;
    }
};