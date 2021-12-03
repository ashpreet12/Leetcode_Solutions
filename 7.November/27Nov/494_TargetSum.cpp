class Solution {
public:
    int findPairs(vector<int> &nums,int idx,int target,map<pair<int,int>,int> &m){
        if(idx < 0 && target == 0){
            return 1;
        }
        if(idx < 0){
            return 0;
        }

        auto it = m.find({idx,target});
        if(it != m.end()){
            return it->second;
        }

        m[{idx,target}] = findPairs(nums,idx-1,target + nums[idx],m) + findPairs(nums,idx-1,target - nums[idx],m);
        return m[{idx,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int> m;
        return findPairs(nums,nums.size() -1,target,m);
    }
};