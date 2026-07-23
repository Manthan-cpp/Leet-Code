class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size(),i=2;
        if (n <= 2)
            return n;
        for (i = 2; i < n; i++) {
            if (n >= 1 << i)
                continue;
            else
                break;
        }
        return 1 << i;
    }
};