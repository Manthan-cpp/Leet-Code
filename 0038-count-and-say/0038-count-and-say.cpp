class Solution {
public:
    string countNums(string s){
        int c=1;
        string ans="";
        for(int i=1;i<=s.length();i++){
            if(i<s.length() && s[i]==s[i-1]){
                c++;
            }
            else{
                ans+=to_string(c);
                ans+=s[i-1];
                c=1;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        int i,j;
        string s="1";
        for(i=1;i<n;i++){
            s=countNums(s);
        }
        return s;
    }
};