#include <algorithm>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = 0, e = nums.size() - 1, k=-1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.size() - 1; j > i; j--) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                k = i + 1;
                break;
            }
        }
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        while (k <= e) {
            swap(nums[k], nums[e]);
            k++;
            e--;
        }
    }
};