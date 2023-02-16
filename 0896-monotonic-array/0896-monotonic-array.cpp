class Solution {
public:
    bool isDescending(vector<int>& nums){
        int elem = nums[0];
        for(auto num : nums){
            if(num > elem){
                return false;
            }
            elem = num;
        }
        return true;
    }
    bool isAscending(vector<int>& nums){
        int elem = nums[0];
        for(auto num : nums){
            if(num < elem){
                return false;
            }
            elem = num;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return isAscending(nums) || isDescending(nums);
    }
};