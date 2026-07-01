#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size(),maxarea=0;
        int i = 0, j = n - 1;
        while (i < j) {
            int width = j - i;
            int height = min(a[i], a[j]);
            int area=height*width;
            maxarea = max(maxarea,area);
            if (a[i] > a[j]) {
                j--;
            } else {
                i++;
            }
        }
        return maxarea;
    }
};