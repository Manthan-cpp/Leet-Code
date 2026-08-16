class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while(n!=1){
            int sum=0;
            while(n){
                int r=n%10;
                sum+=r*r;
                n/=10;
            }
            n=sum;
            if(st.count(n)) return false;
            st.insert(n);
        }
        return true;
    }
};