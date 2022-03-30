class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int idx = 0;
        vector<vector<int>> triangle;
        triangle.push_back({1});
        
        for(int idx = 1; idx < numRows; idx++){
            vector<int> temp(idx + 1, 1);
            for(int i = 1; i < temp.size() - 1 ;i++){
                temp[i] = triangle[idx - 1][i-1] + triangle[idx - 1][i];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};