class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n= grid[0].size();
        vector<vector<int>> ans;
        int arr[m*n];
        if(k%(m*n)==0){
            return grid;
        }
        else{
            k=k%(m*n);
        }
        int ind=0;
        for(int i = 0;i<m;i++)
        {
            for(int j =0 ;j<n;j++){
                arr[ind++]=grid[i][j];
            }
        }
        ind = 0;
        for(int i = 0;i<m;i++){
            vector<int> temprow;
            for(int j = 0 ; j < n ; j++){
                int idx= (ind-k+(m*n))%(m*n);
                int val = arr[idx];
                ind++;
                temprow.push_back(val);
            }
            ans.push_back(temprow);
        }
        return ans;
    }
};