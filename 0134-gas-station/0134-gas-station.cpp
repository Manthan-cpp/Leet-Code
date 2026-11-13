class Solution {
public:
    int canCompleteCircuit(vector<int>& p, vector<int>& c) {
        int deficit=0;
        int balance=0;
        int start=0;
        for(int i=0;i<p.size();i++){
            balance+=p[i]-c[i];
            if(balance<0){
                deficit+=balance;
                start=i+1;
                balance =0;
            }
        }
        if(deficit+balance>=0){
            return start;
        }
        return -1;
    }
};