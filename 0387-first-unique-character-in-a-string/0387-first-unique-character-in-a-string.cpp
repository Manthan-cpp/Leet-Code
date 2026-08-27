class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0}, n=s.length();
        int ans=n;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i]==1){
                char c='a'+i;
                ans=min(ans,(int)s.find(c));
            }
        }
        return ans==n?-1:ans;
    }
};