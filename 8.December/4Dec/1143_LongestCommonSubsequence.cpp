class Solution {
public:
  int lcs(string str1,int m,string str2,int n){
      vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));

      for(int i = 1; i <= m; i++){
          for(int j = 1; j <= n; j++){
              if(str1[i - 1] == str2[j - 1]){
                  dp[i][j] = 1 + dp[i - 1][j - 1];
              }else{
                  dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
              }
          }
      }
      return dp[m][n];
  }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        return lcs(text1,m,text2,n);
    }
};