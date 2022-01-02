class Solution {
public:
    int path(vector<vector<int>>& matrix,int row,int col,int prev,vector<vector<int>>&dp){
        
        int m = matrix.size();
        int n = matrix[0].size();
        if(row < 0 || row > m - 1 || col < 0 || col > n - 1||  prev >= matrix[row][col]){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int val = matrix[row][col];
        if(val > prev){
        dp[row][col] =  1 + 
                max(max(path(matrix,row + 1,col,val,dp),path(matrix,row - 1,col,val,dp)),
                max(path(matrix,row,col + 1,val,dp),path(matrix,row ,col - 1,val,dp)));
        }
        return dp[row][col];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m + 1,vector<int>(n + 1,-1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                ans = max(ans,path(matrix,i,j,-1,dp));
            }
        }
        return ans;
    }
};