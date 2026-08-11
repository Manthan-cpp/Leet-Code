class Solution {
public:
    int maximumScore(int a,int b,int c){
        priority_queue<int> q;
        q.push(a);
        q.push(b);
        q.push(c);
        int ans=0;
        while(q.size()>=2){
            int a=q.top(); q.pop();
            int b=q.top(); q.pop();
            ans++;
            a--; b--;
            if(a) q.push(a);
            if(b) q.push(b);
        }
        return ans;
    }
};