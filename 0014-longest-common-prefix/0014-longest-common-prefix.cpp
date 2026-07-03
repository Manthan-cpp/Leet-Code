#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size(),j=0,c=0,i=0;
        string s="",str="",rest="";
        vector<int> result;
        if(n==0){
            return "";
        }
        if(n==1){
            return strs[0];
        }
        s=strs[i];
        str=strs[i+1];
        if(s[0]!=str[0]){
            return "";
        }
        for(int i=0;i<n-1;i++){
            str=strs[i+1];
            j=0;
            c=0;
            while(j<s.size() && j<str.size()){
                if(s[j]==str[j]){
                    c++;
                    j++;
                }
                else
                {
                    break;
                }
                
            }    
            result.push_back(c);                   
            }
            int res=*min_element(result.begin(),result.end());
            return s.substr(0,res);
        }
    };
