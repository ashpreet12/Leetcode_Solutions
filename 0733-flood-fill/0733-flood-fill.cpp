class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,int startingColor,int color,int m,int n, vector<vector<int>>&visited){
        if(row < 0 || col < 0 || row >= m || col >= n || image[row][col] != startingColor || visited[row][col]){
            return;
        }
        image[row][col] = color;
        visited[row][col] = true;
        
        dfs(image,row+1,col,startingColor,color,m,n,visited);
        dfs(image,row-1,col,startingColor,color,m,n,visited);
        dfs(image,row,col+1,startingColor,color,m,n,visited);
        dfs(image,row,col-1,startingColor,color,m,n,visited);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startingColor = image[sr][sc];
        vector<vector<int>>visited(m + 1, vector<int>(n + 1 , false));
        dfs(image,sr,sc,startingColor,color,m,n,visited);
        return image;
    }
};