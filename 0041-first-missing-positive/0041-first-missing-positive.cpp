#include <algorithm>
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n = nums.size();
        vector<int> a;
        int i = 0,c=0;
        
        sort(nums.begin(), nums.end());
        if(nums[nums.size()-1]<=0){
            return 1;
        }
        while (i < nums.size()) {
            if (nums[i] <= 0) {
                i++;
                c++;
            } else if (nums[i] > 0) {
                a.push_back(nums[i]);
                i++;
            }
        }
        if (a[0] != 1 ) {
            return 1;
        }
        i = 0;
        while (i < a.size()-1) {
            if(a[i]==a[i+1]){
                i++;
            }
            else{
                if(a[i]+1!=a[i+1])
                {
                    break;
                }
                else{
                    i++;
                }
            }
        }
        return a[i]+1;
    }
};  