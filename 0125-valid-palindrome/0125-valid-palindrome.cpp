class Solution {
public:
    bool isPalindrome(string s) {
        int l=s.length();
        int i=0,j=l-1;
        if(l==1){
            return true;
        }
        while(i<=j){
            while(i<=j && !isalnum(s[i])){
                i++;
            }
            while(i<=j && !isalnum(s[j])){
                j--;
            }
            if(i<=j && tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};