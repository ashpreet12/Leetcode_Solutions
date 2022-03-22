//KADANE'S ALGORITHM
class Solution {
public:
    bool isAllNegative(vector<int> &nums){
        for(auto num : nums){
            if(num > 0){
                return false;
            }
        }
        return true;
    }
    int maxSubArray(vector<int>& nums) {
        if(isAllNegative(nums)){
            return *max_element(nums.begin(),nums.end());
        }
        int max_sum = 0;
        int curr_sum = 0;
        
        for(auto num : nums){
            
            curr_sum += num;
            
            if(curr_sum < 0){
                curr_sum = 0;
            }
            
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
        
    }
};