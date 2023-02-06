class Solution {
public:
    int calculateTotalSum(vector<int>& nums){
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {
        int pI = nums.size() - 1;
        bool found = false;
        int leftSum = 0;
        int rightSum = calculateTotalSum(nums);
        for(int idx = 0; idx < nums.size(); idx++){
            rightSum -= nums[idx];
            if(leftSum == rightSum){
                pI = min(pI, idx);
                found = true;
            }
            leftSum += nums[idx];
        }
        return found ? pI : -1;
    }
};