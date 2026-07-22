class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> ans(n);
        k=k%n;
        for(int i=0;i<n;i++){
            // int oldind=i;
            int newind=(i+k)%n;
            ans[newind]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};