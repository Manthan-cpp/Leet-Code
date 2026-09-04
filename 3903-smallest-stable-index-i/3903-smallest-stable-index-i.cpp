class Solution {
public:
    int maxi(int s,int e,vector<int>& nums){
        int mx=nums[s];
        for(int i=s;i<=e;i++){
            mx=max(mx,nums[i]);
        }
        return mx;
    }

    int mini(int s,int e,vector<int>& nums){
        int mn=nums[s];
        for(int i=s;i<=e;i++){
            mn=min(mn,nums[i]);
        }
        return mn;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        // vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mx=maxi(0,i,nums);
            int mn=mini(i,n-1,nums);
            if(mx-mn<=k){
                return i;
            }
        }
        return -1;
    }
};