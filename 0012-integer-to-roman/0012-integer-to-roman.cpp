class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        // if(num>=1000){
        //     while(num>=1000){
        //         num-=1000;
        //         ans+='M';
        //     }
        // }
        // if(num>=900){
        //     while(num>=900){
        //         num-=900;
        //         ans+="CM";
        //     }
        // }
        // if(num>=500){
        //     while(num>=500){
        //         num-=500;
        //         ans+='D';
        //     }
        // }
        // if(num>=400){
        //     while(num>=400){
        //         num-=400;
        //         ans+="CD";
        //     }
        // }
        // if(num>=100){
        //     while(num>=100){
        //         num-=100;
        //         ans+='C';
        //     }
        // }
        // if(num>=90){
        //     while(num>=90){
        //         num-=90;
        //         ans+="XC";
        //     }
        // }
        // if(num>=50){
        //     while(num>=50){
        //         num-=50;
        //         ans+='L';
        //     }
        // }
        // if(num>=40){
        //     while(num>=40){
        //         num-=40;
        //         ans+="XL";
        //     }
        // }
        // if(num>=10){
        //     while(num>=10){
        //         num-=10;
        //         ans+='X';
        //     }
        // }
        // if(num>=9){
        //     while(num>=9){
        //         num-=9;
        //         ans+="IX";
        //     }
        // }
        // if(num>=5){
        //     while(num>=5){
        //         num-=5;
        //         ans+="V";
        //     }
        // }
        // if(num>=4){
        //     while(num>=4){
        //         num-=4;
        //         ans+="IV";
        //     }
        // }
        // if(num>=1){
        //     while(num>=1){
        //         num-=1;
        //         ans+="I";
        //     }
        // }
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50,
                           40,   10,  9,   5,   4,   1};
        vector<string> sym = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};

        for (int i = 0; i < 13; i++) {
            while (num >= val[i]) {
                num -= val[i];
                ans += sym[i];
            }
        }
        return ans;
    }
};