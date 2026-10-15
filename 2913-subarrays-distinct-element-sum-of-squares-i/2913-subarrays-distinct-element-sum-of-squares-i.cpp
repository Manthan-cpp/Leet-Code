class Solution {
public:
    int check(int i,int j, vector<int>& nums){
        int k=i;
        unordered_set<int>st;
        while(k<=j){
            st.insert(nums[k]);
            k++;
        }
        return st.size();
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0,k=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val = check(i,j,nums);
                ans+=val*val;
            }
        }
        return ans;
    }
};