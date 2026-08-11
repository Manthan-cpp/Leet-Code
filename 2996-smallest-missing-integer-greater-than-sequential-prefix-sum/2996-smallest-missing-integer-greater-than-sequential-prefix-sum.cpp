class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = nums[0];

        while (i < n - 1 && nums[i + 1] == nums[i] + 1) {
            i++;
            sum += nums[i];
        }

        while (find(nums.begin(), nums.end(), sum) != nums.end()) {
            sum++;
        }

        return sum;
    }
};