class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int idx=s[i]-'a';
            int revIdx=26-idx;
            ans+=revIdx*(i+1);         
        }
        return ans;
    }
};