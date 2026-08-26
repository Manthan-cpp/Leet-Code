class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, n=s.length();
        int j=0;
        int ones=0;
        string result="";
        while(j<n){
            if(s[j]=='1'){
                ones++;
            }
            while(ones>k || s[i]=='0'){
                if(s[i]=='1')
                    ones--;
                i++;
            }
            if(ones==k){
                string temp = s.substr(i,j-i+1);
                if(result.empty() || result.length()>j-i+1 || (temp.length()==result.length() && temp<result)){
                    result=temp;
                }
            }
            j++;
        }
        return result;
    }
};