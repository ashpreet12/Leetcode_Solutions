class Solution {
public:
    bool isValid(int row,int col,vector<vector<int>>&m){
        return row >= 0 && col >= 0 && row <= m.size() && col < m[row].size(); 
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        
        for(int i = 1; i <= numRows;i++){
            vector<int>triangleRow(i,1);
            for(auto j = 0; j < triangleRow.size();j++){
                if(isValid(i - 2,j - 1,pascalTriangle) && isValid(i - 2,j,pascalTriangle)){
                    triangleRow[j] = pascalTriangle[i - 2][j - 1] + pascalTriangle[i - 2][j];
                }
            }
            pascalTriangle.push_back(triangleRow);
        }
        return pascalTriangle;
    }
};