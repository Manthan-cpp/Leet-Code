class Solution {
public:
    void reverse (vector<int>& nums, int s , int e){
        while(s<e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k=k%n;
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     // int oldind=i;
        //     int newind=(i+k)%n;
        //     ans[newind]=nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     nums[i]=ans[i];
        // }
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};