class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(),maxlen=0,c=0,j=0,i=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(i<j && mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        } 
        return maxlen;
    }
};