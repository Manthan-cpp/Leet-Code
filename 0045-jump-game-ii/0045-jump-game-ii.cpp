class Solution {
public:
    int jump(vector<int>& nums) {
       int jump=0, lastidx=0,coverage=0,destination=nums.size()-1;
       if(nums.size()==1){
        return 0;
       }
       for(int i = 0;i<nums.size();i++){
        coverage = max(coverage,i+nums[i]);
        if(i==lastidx){
            lastidx=coverage;
            jump++;
            if(coverage >= destination){
                return jump;
            }
        }
       }
       return jump;
    }
};