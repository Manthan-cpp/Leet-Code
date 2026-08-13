class Solution {
public:
    struct Node {
        int l,r,pref,suff,best;
    };
    vector<Node> tree;
    string s;
    void merge(int p) {
        Node &cur=tree[p],&L=tree[2*p],&R=tree[2*p+1];
        cur.pref=L.pref;
        cur.suff=R.suff;
        cur.best=max(L.best,R.best);
        if(s[L.r]==s[R.l]) {
            int leftLen=L.r-L.l+1,rightLen=R.r-R.l+1;
            if(L.pref==leftLen) cur.pref+=R.pref;
            if(R.suff==rightLen) cur.suff+=L.suff;
            cur.best=max(cur.best,L.suff+R.pref);
        }
    }
    void build(int p,int l,int r) {
        tree[p]={l,r,1,1,1};
        if(l==r) return;
        int m=(l+r)/2;
        build(2*p,l,m);
        build(2*p+1,m+1,r);
        merge(p);
    }
    void update(int p,int idx,char c) {
        if(tree[p].l==tree[p].r) {
            s[idx]=c;
            return;
        }
        int m=(tree[p].l+tree[p].r)/2;
        if(idx<=m) update(2*p,idx,c);
        else update(2*p+1,idx,c);
        merge(p);
    }
    vector<int> longestRepeating(string s,string queryCharacters,vector<int>& queryIndices) {
        this->s=s;
        int n=s.size();
        tree.resize(4*n+5);
        build(1,0,n-1);
        vector<int> ans;
        for(int i=0;i<queryIndices.size();i++) {
            update(1,queryIndices[i],queryCharacters[i]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};