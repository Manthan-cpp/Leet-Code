class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int len=1;len<=n/2;len++){
            if(n%len!=0){
                continue;
            }
            bool flag=true;
            for(int i=0;i<n;i++){
                if(s[i]!=s[i%len]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};