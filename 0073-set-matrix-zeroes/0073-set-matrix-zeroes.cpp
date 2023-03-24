class Solution {
public:
    void transformRow(int row,vector<vector<int>>& matrix){
        for(int i = 0; i < matrix[row].size();i++){
            matrix[row][i] = 0;
        }
    }
    void transformCol(int col,vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size();i++){
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeroes;
        for(int row = 0; row < matrix.size();row++){
            for(int col = 0; col < matrix[row].size();col++){
                if(matrix[row][col] == 0){
                    zeroes.push_back({row,col});
                }
            }
        }
        for(auto zero : zeroes){
            transformRow(zero.first,matrix);
            transformCol(zero.second,matrix);
        }
    }
};