class Solution {
public:
    bool isBoundary(int row,int col,int m,int n){
        return row + 1 == m || col + 1 == n || row - 1 < 0 || col - 1 < 0;
    }
    
    int countEnclosed(vector<vector<int>>& grid,int row,int col,int m,int n, vector<vector<bool>>&visited,bool &isOutline){
        if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || grid[row][col] == 0){
            return 0;
        }
        visited[row][col] = true;
        if(isBoundary(row,col,m,n)){
            isOutline = true;
        }
        
        return 1 + countEnclosed(grid,row + 1,col,m,n,visited,isOutline) + countEnclosed(grid,row - 1,col,m,n,visited,isOutline) + countEnclosed(grid,row,col + 1,m,n,visited,isOutline) + countEnclosed(grid,row,col - 1,m,n,visited,isOutline);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m + 1, vector<bool>(n + 1, false));
        int enclaves = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                bool isOutline = false;
                int count = 0;
                if(!visited[i][j] && grid[i][j] == 1){
                    count += countEnclosed(grid,i,j,m,n,visited,isOutline);
                }
                if(!isOutline){
                    enclaves += count;
                }
            }
        }
        return enclaves;
    }
};