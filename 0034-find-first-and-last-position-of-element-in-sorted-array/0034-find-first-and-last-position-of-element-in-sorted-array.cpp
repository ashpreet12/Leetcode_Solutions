class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = high - (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
    int findLowest(vector<int>&nums,int idx,int target){
        while(idx >= 0 && nums[idx] == target){
            idx--;
        }
        return idx != -1 ? idx + 1: 0;
    }
    int findHighest(vector<int>&nums,int idx,int target){
        int len = nums.size();
        while(idx < len && nums[idx] == target){
            idx++;
        }
        return idx != len ? idx - 1: len - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binarySearch(nums,target);
        if(idx == -1){
            return {-1, -1};
        }
        return {findLowest(nums,idx,target) , findHighest(nums,idx,target)};
    }
};