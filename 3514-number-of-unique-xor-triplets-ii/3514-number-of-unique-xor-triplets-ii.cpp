class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxel=*max_element(nums.begin(),nums.end());
        int t=1;
        while(t<=maxel){
            t<<=1;
        }
        vector<bool> s1(t,false);
        vector<bool> s2(t,false);
        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<t;i++){
            if(s1[i]==true){
                for(int &num:nums){
                    s2[i^num]=true;
                }
            }
        }
        int c=0;
        for(int i=0;i<t;i++){
            if(s2[i]==true)
                c++;
        }
        return c;
    }
};