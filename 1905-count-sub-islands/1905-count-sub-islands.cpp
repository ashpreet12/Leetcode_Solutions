class Solution {
public:
    void countIslands(vector<vector<int>>& grid,int row,int col,vector<vector<int>>&visited,int m,int n,vector<pair<int,int>> &v){
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0 || visited[row][col] == true){
            return;
        }

        visited[row][col] = true;
        v.push_back({row,col});

        countIslands(grid,row+1,col,visited,m,n,v);
        countIslands(grid,row-1,col,visited,m,n,v);
        countIslands(grid,row,col+1,visited,m,n,v);
        countIslands(grid,row,col-1,visited,m,n,v);
    }
    vector<vector<pair<int,int>>> getIslandSqaures(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m + 1 , vector<int>(n + 1 , false));
        vector<vector<pair<int,int>>>islandsquares;
        
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                vector<pair<int,int>> v;
                if(visited[i][j] == false && grid[i][j] == 1){
                    countIslands(grid,i,j,visited,m,n,v);
                    islandsquares.push_back(v);
                }
            }
        }
        return islandsquares;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<pair<int,int>>> isq = getIslandSqaures(grid2);
        int subislands = 0;
        for(auto vec : isq){
            bool isSubisland = true;
            for(auto p : vec){
                if(grid1[p.first][p.second] == 0){
                    isSubisland = false;
                }
            }
            if(isSubisland){
                subislands++;
            }
        }
        return subislands;
    }
};