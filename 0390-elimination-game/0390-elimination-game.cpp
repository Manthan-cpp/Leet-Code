class Solution {
public:
    int solve(int n,int head , int step, bool left){
       if(n==1){
        return head;
       }
       if(left || n%2==1){
        head+=step;
       }
       return solve(n/2,head,step*2,!left);
    }
    int lastRemaining(int n) {
        return solve(n,1,1,true);
    }
};