class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m =  mat.size();
        int n =  mat[0].size();
        
        if(r * c != m * n){
            return mat;
        }
        
        vector<int> arr;
        for(auto row : mat){
            for(auto col : row){
                arr.push_back(col);
            }
        }
        
        vector<vector<int>> ans;
        int idx = 0;
        
        for(int i = 0; i < r;i++){
            vector<int> col;
            for(int j = 0; j < c;j++){
                col.push_back(arr[idx]);
                idx++;
            }
            ans.push_back(col);
        }
        return ans;
    }
};