class Solution {
public:

    int min_jumps(vector<int>& nums,int start,int end,vector<int>&dp){
        if(start >= end){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int steps = 0;
        int minJumps = INT_MAX;

        for(int i = 1; i <= nums[start];i++){
            steps = 1 + min_jumps(nums,start + i,end,dp);
            minJumps = min(minJumps,steps);
        }
        if(minJumps > end){
            minJumps = end;
        }
        dp[start] =  minJumps;
        return dp[start];
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, -1);
        return min_jumps(nums,0,nums.size() - 1,dp);
    }
};