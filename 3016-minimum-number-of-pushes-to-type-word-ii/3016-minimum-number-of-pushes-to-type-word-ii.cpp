class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ans(26,0);
        for(int i=0;i<word.length();i++){
            int ind = word[i]-'a';
            ans[ind]++;
        }   
        sort(begin(ans),end(ans),greater<int>());
        int res=0;
        for(int i=0;i<26;i++){
            int freq = ans[i];
            res+=freq*(i/8+1);
        }
        return res;
    }
};