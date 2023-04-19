class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> m;
        
        for(int i = 0; i < heights.size();i++){
            m[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end(),greater<int>());
        
        vector<string> sortedPeople;
        
        for(auto height : heights){
            sortedPeople.push_back(m[height]);
        }
        return sortedPeople;
    }
};