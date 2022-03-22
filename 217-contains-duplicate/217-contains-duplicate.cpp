class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(auto num : nums){
            m[num]++;
            
            if(m.find(num) != m.end() && m[num] >= 2){
                return true;
            }
        }
        return false;
    }
};