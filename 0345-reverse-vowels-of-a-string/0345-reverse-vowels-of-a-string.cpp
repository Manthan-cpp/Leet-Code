class Solution {
public:
    string reverseVowels(string s) {
        string v="aeiouAEIOU";
        int l=0,r=s.size()-1;
        while(l<r){
            while(l<r&&v.find(s[l])==string::npos) l++;
            while(l<r&&v.find(s[r])==string::npos) r--;
            swap(s[l++],s[r--]);
        }
        return s;
    }
};