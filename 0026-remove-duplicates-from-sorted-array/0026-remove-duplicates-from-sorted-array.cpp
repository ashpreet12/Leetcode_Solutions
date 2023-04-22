class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicate = nums[0];
        for(int i = 1; i < nums.size();i++){
            if(nums[i] == duplicate){
                nums[i] = INT_MAX;
            }else{
                duplicate = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        int count = 0;
        
        for(auto num : nums){
            if(num == INT_MAX){
                return count;
            }
            count++;
        }
        return count;
    }
};