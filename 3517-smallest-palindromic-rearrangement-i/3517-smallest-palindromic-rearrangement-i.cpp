class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n==1||n==3){
            return s;
        }
        sort(s.begin(),s.begin()+n/2);
        sort(s.begin()+(n+1)/2,s.end(), greater<char>());
        return s;
    }
};