class MinStack {
        stack<long long> s;
        long long mini;
public:
    MinStack() {}
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            mini=value;
        }
        else{
            if(value<mini){
                s.push(2LL*value-mini);
                mini=value;
            }else{
                s.push(value);
            }
        }
    }
    
    void pop() {
        long long curr=s.top();
        if(curr<mini){
            mini=2LL*mini-curr;
        }
        s.pop();
    }
    
    int top() {
        long long curr = s.top();
        if(curr<mini){
            return mini;
        }
        else{
            return curr;
        }
    }
    
    int getMin() {
        return mini; 
    }
};

