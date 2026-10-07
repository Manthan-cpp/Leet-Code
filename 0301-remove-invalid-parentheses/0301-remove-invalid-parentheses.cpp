class Solution {
public:
    set<string> ans;
    int n;

    void dfs(string &s,int i,int l,int r,int lc,int rc,string cur) {
        if(i==n) {
            if(l==0 && r==0)
                ans.insert(cur);
            return;
        }

        if(n-i<l+r || rc>lc)
            return;

        if(s[i]=='(' && l>0)
            dfs(s,i+1,l-1,r,lc,rc,cur);

        if(s[i]==')' && r>0)
            dfs(s,i+1,l,r-1,lc,rc,cur);

        if(s[i]=='(')
            dfs(s,i+1,l,r,lc+1,rc,cur+'(');
        else if(s[i]==')') {
            if(lc>rc)
                dfs(s,i+1,l,r,lc,rc+1,cur+')');
        }
        else
            dfs(s,i+1,l,r,lc,rc,cur+s[i]);
    }

    vector<string> removeInvalidParentheses(string s) {
        n=s.size();

        int l=0,r=0;

        for(char c:s) {
            if(c=='(')
                l++;
            else if(c==')') {
                if(l>0)
                    l--;
                else
                    r++;
            }
        }

        string cur;
        dfs(s,0,l,r,0,0,cur);

        return vector<string>(ans.begin(),ans.end());
    }
};