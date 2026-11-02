class Solution {
public:
    int calPoints(vector<string>& s) {
        int ans=0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="C"){
                st.pop();
            }   
            else if(s[i]=="D"){
                st.push(st.top()*2);
            }
            else if(s[i]=="+"){
                int a=st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else{
                st.push(stoi(s[i]));
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};