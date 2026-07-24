class Solution {
public:
    // void toggle(vector<bool>& bulbs, int i, int n) {

    //     for (int j = i; j <= n; j = j + i) {
    //         bulbs[j-1] = bulbs[j-1] ? false : true;
    //     }
    // }
    int bulbSwitch(int n) {
        // if(n==1){
        //     return 1;
        // }
        // vector<bool> bulbs(n,false);

        // // bulbs[0] = !bulbs[0];
        // for (int i = 1; i <=n; i++) {
        //     toggle(bulbs, i , n);
        // }
        // int c = 0;
        // for (int i = 0; i < bulbs.size(); i++) {
        //     if (bulbs[i]) {
        //         c++;
        //     }
        // }
        // return c;
        return sqrt(n);
    }
};