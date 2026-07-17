class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int c=0, endrow = matrix.size()-1, startcol = matrix[0].size()-1,
            total = matrix.size() * matrix[0].size(),startrow=0,endcol=0;
            while(c<total){
                for(int i=endcol;c<total && i<=startcol;i++){
                    ans.push_back(matrix[startrow][i]);
                    c++;
                }
                startrow++;
                for(int i = startrow;c<total && i<=endrow;i++){
                    ans.push_back(matrix[i][startcol]);
                    c++;
                }
                startcol--;
                for(int i = startcol;c<total && i>=endcol;i--){
                    ans.push_back(matrix[endrow][i]);
                    c++;
                }
                endrow--;
                for(int i = endrow;c<total && i>=startrow;i--){
                    ans.push_back(matrix[i][endcol]);
                    c++;
                }
                endcol++;
            }
            return ans;
    }
};