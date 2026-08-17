class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n=columnNumber;
        string res="";
        while(n!=0){
            n--;
            int r = n%26;
            char c=('A'+r);
            res+=c;
            n/=26;
        }
        int i=0,j=res.length()-1;
        while(i<=j){
            swap(res[i],res[j]);
            i++;
            j--;
        }
        return res;
    }
};