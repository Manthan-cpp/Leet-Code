class Solution {
public:
    int n;
    bool isPalindrome(string& s,int i,int j){
        // int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s,int k,int i,int j,vector<vector<int>>&t){
        if(i>=n || j>=n){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(isPalindrome(s,i,j)){
            int take=1+solve(s,k,j+1,j+k,t);
            int grow=solve(s,k,i,j+1,t);
            int slide=solve(s,k,i+1,j+1,t);
            return t[i][j]=max({take,grow,slide});
        }
        int slide=solve(s,k,i+1,j+1,t);
        int grow=solve(s,k,i,j+1,t);
        return t[i][j]= max({grow,slide});
    }
    int maxPalindromes(string s, int k) {
        n=s.length();
        if(k==1){
            return n;
        }
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        return solve(s,k,0,k-1,t);
    }
};