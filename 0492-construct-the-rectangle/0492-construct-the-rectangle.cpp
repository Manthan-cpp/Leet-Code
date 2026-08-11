class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i=1,j=1,L=1,W=1;
        // if(isPrime(area)){
        //     return {area,1};
        // }
        while(i*i<=area){
            if(i*i==area){
                return {i,i};
            }
            i++;
        }
        for(j=i;j>=0;j--){
            if(area%j==0){
                W=j;
                break;
            }
        }
        L=area/W;
        if(L>W){
            return {L,W};
        }
        return {W,L};
    }
};