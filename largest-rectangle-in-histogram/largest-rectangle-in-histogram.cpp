class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        stack<int> st;
        int max_area = 0;
        
        for(int i = 0; i < n; ++i) {
            int curr = heights[i];
            
            while(!st.empty() && heights[st.top()] >= curr) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                
                int curr_area = height * width;
                max_area = max(max_area, curr_area);
            }
            
            st.push(i);
        }
        
        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            
            int curr_area = height * width;
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};