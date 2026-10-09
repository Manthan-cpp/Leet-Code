class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int c=0,result=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                c++;
                i++;
            }
            else{
                if(c>0){
                    c--;
                }else{
                    result++;
                }
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                }
                else{
                    result++;
                    i++;
                }
            }
        }
        return result + c*2;
    }
};