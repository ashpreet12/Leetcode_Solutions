class Solution {
public:
    int areaDfs(vector<vector<int>>& grid,int row,int col,int m,int n,vector<vector<bool>>&visited){
        if(row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || grid[row][col] == 0){
            return 0;
        }
        visited[row][col] = true;
        return 1 + areaDfs(grid,row+1,col,m,n,visited) + areaDfs(grid,row-1,col,m,n,visited) +
            areaDfs(grid,row,col+1,m,n,visited) + areaDfs(grid,row,col-1,m,n,visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m+1,vector<bool>(n+1,false));
        int maxArea = 0;
        
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    maxArea = max(maxArea,areaDfs(grid,i,j,m,n,visited));
                }
            }
        }
        return maxArea;
    }
};