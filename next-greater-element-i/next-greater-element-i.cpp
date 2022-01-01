class Solution {
public:
  
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> st;
        
        for(int i = 0; i < nums2.size();i++){
            
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                m.insert({nums2[st.top()],nums2[i]});
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            m.insert({nums2[st.top()] , -1});
            st.pop();
        }
        
        
        vector<int>next;
        for(int i = 0; i < nums1.size();i++){
            auto it = m.find(nums1[i]);
            if(it != m.end()){
                next.push_back(it->second);
            }
        }
        return next;
        
    }
};