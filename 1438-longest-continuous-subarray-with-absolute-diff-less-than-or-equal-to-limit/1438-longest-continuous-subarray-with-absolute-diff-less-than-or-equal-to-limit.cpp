class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int low = 0;
        int high = 0;
        
        multiset<int> m;
        int max_len = 0;
        
        while(low <= high && high < nums.size()){
            m.insert(nums[high]);
            
            while(!m.empty() && *m.rbegin() - *m.begin() > limit){
                //ERASE ONLY ONE INSTANCE OF THE ELEMENT
                m.erase(m.find(nums[low]));
                low++;
            }
            if(*m.rbegin() - *m.begin() <= limit){
                max_len = max(max_len,high - low + 1);
            }
              
            high ++;
        }
        
        return max_len;
    }
};