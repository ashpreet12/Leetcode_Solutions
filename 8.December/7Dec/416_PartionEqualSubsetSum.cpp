class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);

		if (totalSum % 2 != 0){
            return false;
        }
		int len = nums.size();
        vector<vector<bool>>dp(len + 1,vector<bool>(totalSum / 2 + 1));

        dp[0][0] = true;

		for (int i = 1; i <= len; i++) {
			for (int j = 1; j < totalSum / 2 + 1; j++) {

                if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]]){
                    dp[i][j] = true;
                }
				else{
                    dp[i][j] = dp[i - 1][j];
                }
			}
		}
		return dp[len][totalSum / 2];
	}
};