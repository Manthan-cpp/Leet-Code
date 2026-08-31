class Solution {
public:
    char findTheDifference(string s, string t) {
        int ns=s.length();
        int nt=t.length();
        if(s.empty()){
            return t[0];
        }
        int arr[26]={0};
        int arr2[26]={0};
        for(int i=0;i<ns;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<nt;i++){
            arr2[t[i]-'a']++;
        }
        char ans;
        for(int i=0;i<26;i++){
            if(arr2[i]!=arr[i]){
                ans=i+'a';
            }
        }
        return ans;
    }
};