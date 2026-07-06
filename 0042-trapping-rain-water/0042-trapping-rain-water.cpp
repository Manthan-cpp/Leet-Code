#include <algorithm>
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),i=0,max1=0,max2=0;
        int j=n-1;
        vector<int> r; 
        vector<int> l;
        vector<int> fin;
        if(height.empty()){
            return 0;
        }
        max1=height[0];
        while(i<n){
            max1=max(max1,height[i]);
            l.push_back(max1);
            i++;
        } 
        max2=height[n-1];
        while(j>=0){
            max2=max(max2,height[j]);
            r.push_back(max2);
            j--;
        }
        reverse(r.begin(),r.end());
        i=0;
        while(i<n){
            fin.push_back(min(l[i],r[i])-height[i]);
            i++;
        }
        int sum=0;
        for(int i=0;i<fin.size();i++){
            sum+=fin[i];
        }
        return sum;
    }
};