class Solution {
public:
    int lps(string &str,int start,int end,vector<vector<int>>&dp){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        if(str[start] == str[end]){
            dp[start][end] =  2 + lps(str, start + 1, end - 1,dp);
        }else{
            dp[start][end] =  max(lps(str,start + 1,end,dp) , lps(str,start,end - 1,dp));
        }

      return dp[start][end];
    }
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>>dp(len + 1,vector<int>(len + 1,-1));
        return lps(s,0,s.size() - 1,dp);
    }
};