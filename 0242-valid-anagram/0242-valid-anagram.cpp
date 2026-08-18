class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int arrS[26]={0};
        int arrT[26]={0};
        for(int i=0;i<s.length();i++){
            arrS[s[i]-'a']++;
            arrT[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arrS[i]!=arrT[i]){
                return false;
            }
        }
        return true;
    }
};