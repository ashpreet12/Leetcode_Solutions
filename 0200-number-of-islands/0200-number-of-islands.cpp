class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row,int col,int m ,int n,vector<vector<bool>>&visited){
        if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || grid[row][col] == '0'){
            return;
        }
        visited[row][col] = true;
        
        dfs(grid,row+1,col,m,n,visited);
        dfs(grid,row-1,col,m,n,visited);
        dfs(grid,row,col+1,m,n,visited);
        dfs(grid,row,col-1,m,n,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m+1,vector<bool>(n+1,false));
        int islands = 0;
        for(int i = 0; i < m;i++){
            for(int j = 0 ; j < n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid,i,j,m,n,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};