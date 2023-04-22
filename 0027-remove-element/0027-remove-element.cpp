class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int removed = -1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == val){
                nums[i] = removed;
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int count = 0;
        for(auto num : nums){
            if(num == removed){
                return count;
            }
            count++;
        }
        return count;
    }
};