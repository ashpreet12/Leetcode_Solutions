class Solution {
public:
    unordered_map<int,int> createMap(vector<int> arr){
        unordered_map<int,int> m;
        for(auto num : arr){
            m[num]++;
        }
        return m;
    }
    void putValues(vector<int> &ans,int val,int times){
        for(int i = 0; i < times;i++){
            ans.push_back(val);
        }
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1 = createMap(nums1);
        unordered_map<int,int> m2 = createMap(nums2);
        
        vector<int> ans;
       
        for(auto &x : m1){
            auto y = m2.find(x.first);
            if(y != m2.end()){
                putValues(ans,x.first,min(x.second, y->second));
            }
        }
        return ans;
    }
};