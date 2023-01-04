class Solution {
public:
    bool isPresent(int day,vector<int>& days){
        for(int x : days){
            if(x == day){
                return true;
            }
        }
        return false;
    }
    int minCost(int s,vector<int>& days, vector<int>& costs,vector<int> &dp){

        if(s > days[days.size() - 1]){
            return 0;
        }
        if(dp[s] != -1){
            return dp[s];
        }
        if(!isPresent(s,days)){
            dp[s] =  minCost(s+1,days,costs,dp);
            return dp[s];
        }
        int OnePass = costs[0] + minCost(s + 1,days,costs,dp);
        int sevenPass = costs[1] + minCost(s + 7,days,costs,dp);
        int thirtyPass = costs[2] + minCost(s + 30,days,costs,dp);

        dp[s] =  min(OnePass,min(sevenPass,thirtyPass));
        return dp[s];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days[days.size() - 1] + 1,-1);
        return minCost(days[0],days,costs,dp);
    }
};