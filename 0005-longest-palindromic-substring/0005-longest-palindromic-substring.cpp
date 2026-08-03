class Solution {
public:
    int t[1001][1001];
    bool solve(string &s,int i,int j){
        if(i>=j){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            return t[i][j]=solve(s,i+1,j-1);
        }
        return t[i][j]=0;
    }
    string longestPalindrome(string s) {
        int l=s.length();
        memset(t,-1,sizeof(t));
        int sp=0,maxlen=INT_MIN;
        for(int i=0;i<l;i++){
            for(int j=i;j<l;j++){
                if(solve(s,i,j)){
                    if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    sp=i;

                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};