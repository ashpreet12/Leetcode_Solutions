class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>countArray(3,0);
        for(auto num : nums){
            countArray[num]++;
        }
        int idx = 0;
        while(countArray[0] != 0){
            nums[idx] = 0;
            idx++;
            countArray[0]--;
        }
        
        while(countArray[1] != 0){
            nums[idx] = 1;
            idx++;
            countArray[1]--;
        }
        
        while(countArray[2] != 0){
            nums[idx] = 2;
            idx++;
            countArray[2]--;
        }
    }
};