class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans="";
        string say=countAndSay(n-1);
        for(int i=0;i<say.length();i++){
            char ch=say[i];
            int c=1;
            while(i<say.length() && say[i]==say[i+1]){
                c++;
                i++;
            }
            ans+=to_string(c)+string(1,ch);
        }
        return ans;
    }
};