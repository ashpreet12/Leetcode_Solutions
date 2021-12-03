class Solution {
public:
    bool isValid(vector<int>& nums, int start,int end,vector<int>&memo){
        if(memo[start] != -1){
            return memo[start];
        }
        if(start >= end){
            return true;
        }
        for(int i = 1; i <= nums[start]; i++){
            if(isValid(nums,start + i,end,memo) == 1){
                return true;
            }
        }
        memo[start] = false;
        return memo[start];
    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size() + 1,-1);
        return isValid(nums, 0,nums.size() - 1,memo);
    }
};