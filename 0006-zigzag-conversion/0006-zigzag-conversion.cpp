class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows,"");
        int n=s.length();
        if(numRows==1||numRows>n){
            return s;
        }
        int i=0;
        while(i<n){
            for(int idx=0;idx<numRows && i<n;idx++){
             ans[idx]+=s[i++];
            }
            for(int idx=numRows-2;idx>0 && i<n;idx--){
                ans[idx]+=s[i++];
            }
        }
        string res="";
        for(string &x:ans){
            res+=x;
        }
        return res;
    }
};