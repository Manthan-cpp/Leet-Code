class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=s.length();
        int i=0,j=0;
        int count[26]={0},maxlen=0;
        while(j<l){
            count[s[j]-'a']++;
            while(i<j && count[s[j]-'a']>2){
                count[s[i]-'a']--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }   
        return maxlen;
    }
};