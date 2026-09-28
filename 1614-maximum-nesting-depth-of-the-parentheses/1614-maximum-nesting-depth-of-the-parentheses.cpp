class Solution {
public:
    int maxDepth(string s) {
        int c=0,maxi=INT_MIN;
        vector<int> counts;
        // if(s.length()<=1){
        //     return 0;
        // }
        for(int i=0;i<s.length();i++){
            maxi=max(maxi,c);
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')'){
                c--;
            }
        }   
        return maxi;
    }
};