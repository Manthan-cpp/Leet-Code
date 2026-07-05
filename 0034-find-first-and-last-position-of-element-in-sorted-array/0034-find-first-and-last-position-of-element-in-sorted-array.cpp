class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector<int> result;
        if( nums.empty()){
            return {-1,-1};
        }
        while (i < nums.size()) {
            if (nums[i] == target) {
                result.push_back(i);
                break;
            } else {
                i++;
            }
        }
        while (j >= 0) {
            if (nums[j] == target) {
                result.push_back(j);
                break;
            } else {
                j--;
            }
        }
        if (result.empty()) {
            return {-1, -1};
        } else {
            return result;
        }
    }
};