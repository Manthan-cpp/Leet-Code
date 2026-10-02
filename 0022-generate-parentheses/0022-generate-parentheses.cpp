class Solution {
public:
    vector<string> result;
    bool isValid(string&s){
        int count=0;
        for(char &c:s){
            if(count<0){
                return false;
            }
            if(c=='('){
                count++;
            }
            else{
                count--;
            }
        }
        return (count==0)?true:false;
    }
    void solve(string &curr,int n ){
        if(curr.length()==2*n){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return result;   
    }
};