class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        unordered_map<string,vector<string>> groups;
        
        for(auto str : strs){
            string curr = str;
            sort(str.begin(),str.end());
            groups[str].push_back(curr);
        }
        
        for(auto group : groups){
            groupedAnagrams.push_back(group.second);
        }
        return groupedAnagrams;
    }
};