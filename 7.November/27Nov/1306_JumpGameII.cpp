class Solution {
public:
    bool isValid(vector<int>& arr, int start,vector<bool> &visited,vector<int>&dp){
        if(start < 0 || start > arr.size() - 1){
            return false;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        if(visited[start] == true){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }
        visited[start] = true;
dp[start] =  isValid(arr,start + arr[start],visited,dp)|| isValid(arr,start -arr[start],visited,dp);
        return dp[start];
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size() , false);
        vector<int>dp(arr.size() + 1,-1);
        return isValid(arr,start,visited,dp);
    }
};