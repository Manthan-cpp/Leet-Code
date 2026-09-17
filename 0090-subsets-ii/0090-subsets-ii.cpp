class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int)> dfs = [&](int i) {
            ans.push_back(cur);
            for (int j = i; j < nums.size(); j++) {
                if (j > i && nums[j] == nums[j - 1]) continue;
                cur.push_back(nums[j]);
                dfs(j + 1);
                cur.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};