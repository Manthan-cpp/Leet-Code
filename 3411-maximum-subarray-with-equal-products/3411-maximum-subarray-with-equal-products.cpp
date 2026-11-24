
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int maxLcm = 1, maxNum = 1;

        for (int x : nums) {
            maxLcm = lcm(maxLcm, x);
            maxNum = max(maxNum, x);
        }

        long long limit = 1LL * maxLcm * maxNum;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int g = 0, l = 1;

            for (int j = i; j < n; j++) {

                if (prod > limit / nums[j])
                    break;

                prod *= nums[j];

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (prod == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
