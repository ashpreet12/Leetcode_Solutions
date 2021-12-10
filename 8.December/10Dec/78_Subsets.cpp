class Solution {
public:
    vector<vector<int>> ans;
    void getSubsets(int start,vector<int>& nums,vector<int>temp){
        if(start > nums.size() - 1){
            ans.push_back(temp);
            return;
        }
        vector<int>include = temp;
        include.push_back(nums[start]);

        getSubsets(start + 1,nums,include);
        getSubsets(start + 1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        getSubsets(0,nums,{});
        return ans;
    }
};