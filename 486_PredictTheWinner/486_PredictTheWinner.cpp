class Solution {
public:
    int winner(vector<int> &nums,int start,int end){
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int> (len + 1,-1));

    }
    int winner(vector<int>& nums,int start,int end,vector<vector<int>> &dp){
        if(start == end){
            return nums[start];
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        dp[start][end] =  max(nums[start] - winner(nums,start + 1,end,dp),nums[end] - winner(nums,start,end- 1,dp));
        return dp[start][end];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 1, vector<int> (len + 1,-1));
        return winner(nums,0,nums.size() - 1,dp) >= 0;
    }
};