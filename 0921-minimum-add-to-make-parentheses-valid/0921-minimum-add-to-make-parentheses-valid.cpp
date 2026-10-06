class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0,open=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                size++;
            }
            else{
                if(size==0){
                    open++;
                }
                else{
                    size--;
                }
            }
        }
        return size+open;
    }
};