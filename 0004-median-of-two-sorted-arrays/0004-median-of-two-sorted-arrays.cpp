#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int a[n], s = 0, e = n - 1;
        int mid = (s + e) / 2;
        int i=0;
        double median =0;
        for ( i = 0; i < nums1.size(); i++) {
            a[i] = nums1[i];
        }
        for (int j = 0; j < nums2.size(); j++) {
            a[i++] = nums2[j];
        }
        sort(a,a+n);
        if (n % 2 == 0) {
            median = (a[mid]+a[mid + 1])/2.0;
        }
        else{
            median = a[mid];
        }
        return median;
    }
};