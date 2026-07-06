class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int i = 0, j = n - 1;
        int max1 = 0, max2 = 0;
        int sum = 0;

        while (i < j) {
            if (height[i] <= height[j]) {
                if (height[i] >= max1)
                    max1 = height[i];
                else
                    sum += max1 - height[i];
                i++;
            } else {
                if (height[j] >= max2)
                    max2 = height[j];
                else
                    sum += max2 - height[j];
                j--;
            }
        }

        return sum;
    }
};