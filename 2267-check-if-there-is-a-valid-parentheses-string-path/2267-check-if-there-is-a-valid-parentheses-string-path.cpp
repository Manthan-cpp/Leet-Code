class Solution {
public:
    int m,n;
    int t[101][101][201];
    bool solve(int i,int j,int openc,vector<vector<char>>& grid){
        openc+=(grid[i][j]=='(')?1:-1;
        if(openc<0){
            return false;
        }
        if(t[i][j][openc]!=-1){
            return t[i][j][openc];
        }
        
        if(i==m-1 && j==n-1){
            return t[i][j][openc] = (openc==0);
        }
        if(i+1<m){
            if(solve(i+1,j,openc,grid)){
                return t[i][j][openc]= true;
            }
        }
        if(j+1<n){
            if(solve(i,j+1,openc,grid)){
                return t[i][j][openc]= true;
            }
        }
        return t[i][j][openc]= false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size(); 
        n=grid[0].size(); 
        if((n+m-1)%2==1){
            return false;
        }
        if(grid[0][0]==')' || grid[m-1][n-1]=='('){
            return false;
        }
        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};