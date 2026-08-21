class Solution {
public:
    int addDigits(int num) {
        int n=num,sum=0,r;
        while(num>=10) {
            n=num;
            while (n) {
                r = n % 10;
                sum = sum + r;
                n /= 10;
            }
            num=sum;
            sum=0;
        }
        return num;
    }
};