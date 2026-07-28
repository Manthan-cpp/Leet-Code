class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length(),j=0;
        if(n==1||n==3){
            return s;
        }
        sort(s.begin(),s.begin()+n/2);
        j=n-1;
        int i=0;
        while(j>=(n+1)/2){
            s[j]=s[i];
            i++;
            j--;
        }
        return s;
    }
};