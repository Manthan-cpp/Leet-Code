class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for(int i : nums) {
            total += i;
        }

        int target = total - x;

        if(target < 0) {
            return -1;
        }

        if(target == 0) {
            return nums.size();
        }

        int left = 0;
        int sum = 0;
        int maxi = -1;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxi = max(maxi, right - left + 1);
            }
        }

        if(maxi == -1) {
            return -1;
        }

        return nums.size() - maxi;
    }
};