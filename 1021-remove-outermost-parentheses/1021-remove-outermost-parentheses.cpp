class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && c==0){
                c++;
                continue;
            }
            else if(s[i]==')' && c==1){
                c--;
                continue;
            }
            if(s[i]=='('){
                c++;
            }
            else{
                c--;
            }
            ans=ans+s[i];
        }
        return ans;
    }
};