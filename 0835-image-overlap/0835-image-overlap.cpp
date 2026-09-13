class Solution {
public:
    int countOverlaps(vector<vector<int>>& a, vector<vector<int>>& b,int rowoff,int coloff){
        int n=a.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bi=i+rowoff;
                int bj=j+coloff;
                if(bi<0||bi>=n||bj<0||bj>=n){
                    continue;
                }
                if(a[i][j]==1&&b[bi][bj]==1){
                    c++;
                }
            }
        }
        return c;
    }
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size();
        int maxoverlap=0;
        for(int rowoff=-n+1;rowoff<n;rowoff++){
            for(int coloff=-n+1;coloff<n;coloff++){
                int c=countOverlaps(a,b,rowoff,coloff);
                maxoverlap=max(maxoverlap,c);
            }
        }
        return maxoverlap;
    }
};