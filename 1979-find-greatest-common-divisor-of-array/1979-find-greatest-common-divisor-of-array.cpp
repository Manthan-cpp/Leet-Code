#include <algorithm>
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx , mn , ans;
        mx= *max_element(nums.begin(),nums.end());
        mn= *min_element(nums.begin(),nums.end());
        for(int i=1;i<=mn;i++){
            if(mn%i==0 && mx%i==0){
                ans=i;
            }
        }
        return ans;
    }
};