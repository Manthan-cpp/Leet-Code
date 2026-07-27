class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2=1;
        int i3=1;
        int i5=1;
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int i2ugly=arr[i2]*2;
            int i3ugly=arr[i3]*3;
            int i5ugly=arr[i5]*5;
            int minUgly=min({i2ugly,i3ugly,i5ugly});
            arr[i]=minUgly;
            if(i2ugly==minUgly)
                i2++;
            if(i3ugly==minUgly)
                i3++;
            if(i5ugly==minUgly)
                i5++;
        }
        return arr[n];
    }
};