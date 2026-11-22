class Solution {
public:
    bool checkString(string s) {
        int a=0,b=0;
        for(char &ch: s){
            if(ch == 'a'){
                if(b){
                    return false;
                }
                a++;
            }
            else{
                b++;
            }
        }
        return true;
    }
};