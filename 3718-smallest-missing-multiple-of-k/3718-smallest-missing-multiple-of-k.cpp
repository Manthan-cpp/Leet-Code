class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=k;
        while (find(nums.begin(), nums.end(), ans) != nums.end()) {

            ans+=k;
        }
        return ans;
    }
};