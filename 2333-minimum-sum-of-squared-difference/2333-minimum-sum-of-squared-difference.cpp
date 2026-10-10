class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<int> cdiff(1e5+1,0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            cdiff[d]++;
        }
        int k=k1+k2;
        for(int i=1e5;i>0 && k>0;i--){
            int cops=min(cdiff[i],k);
            cdiff[i]-=cops;
            cdiff[i-1]+=cops;
            k-=cops;
        }
        long long res=0;
        for(long long d=1;d<=1e5;d++){
            res+=cdiff[d]*(d*d);
        }
        return res;
    }
};