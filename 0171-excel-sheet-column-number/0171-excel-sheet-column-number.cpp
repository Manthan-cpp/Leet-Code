class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length(),ans=0;
        for(int i=0;i<n;i++){
            int dig = columnTitle[i]-'A'+1;
            ans=ans*26+dig;
        }
        return ans;
    }
};