class Solution {
public:
    int getDigitSum(int n){
        int sum=0;
        while(n>0){
            int r=n%10;
            sum+=r;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>afsort(nums);
        auto lambda = [this](int num1,int num2){
            int num1DigitSum=getDigitSum(num1);
            int num2DigitSum=getDigitSum(num2);
            if(num1DigitSum!=num2DigitSum){
                return num1DigitSum<num2DigitSum;
            }
            return num1<num2;
        };
        sort(begin(afsort),end(afsort),lambda);
        unordered_map<int,int> valToIdx;
        for(int i=0;i<n;i++){
            valToIdx[nums[i]]=i;
        }
        int swapCount=0;
        for(int i=0;i<n;i++){
            int expectedVal=afsort[i];
            int currVal=nums[i];
            if(expectedVal==currVal){
                continue;
            }
            int idx=valToIdx[expectedVal];
            nums[i]=expectedVal;
            nums[idx]=currVal;
            valToIdx[expectedVal]=i;
            valToIdx[currVal]=idx;
            swapCount++;
        }
        return swapCount;
    }
};