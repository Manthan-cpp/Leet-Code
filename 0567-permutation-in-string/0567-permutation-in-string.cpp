class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m){
            return false;
        }
        vector<int> a(26,0);
        vector<int> b(26,0);
        
        for(char &ch:s1){
            a[ch-'a']++;
        }
        int i=0,j=0;
        while(j<m){
            b[s2[j]-'a']++;
            if(j-i+1>n){
                b[s2[i]-'a']--;
                i++;
            }
            if(a==b){
                return true;
            }
            j++;
        }
        return false;
    }
};