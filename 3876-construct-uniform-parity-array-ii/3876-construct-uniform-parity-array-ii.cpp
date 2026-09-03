class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallodd=INT_MAX;
        for(int x: nums1){
            if(x%2==1){
            smallodd=min(smallodd,x);
            }
        }
        if(smallodd==INT_MAX){
            return true;
        }
        for(int x:nums1){
            if(x%2==0 && x<=smallodd){
                return false;
            }
        }
        return true;
    }
};