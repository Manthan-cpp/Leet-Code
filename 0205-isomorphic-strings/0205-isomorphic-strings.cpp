class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.length();
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        for(int i=0;i<len;i++){
            char ch1=s[i];
            char ch2=t[i];
            if(mp1.find(ch1)!=mp1.end() && mp1[ch1]!=ch2 ||
               mp2.find(ch2)!=mp2.end() && mp2[ch2]!=ch1){
                return false;
               }
            mp1[ch1]=ch2;
            mp2[ch2]=ch1;
        }
        return true;
    }
};