class Solution {
public:
vector<string> ans;
void letter(string digits,int start,string str,unordered_map<int,vector<char>> &m) {
      if(str.length() == digits.length()){
        if(str != ""){
            ans.push_back(str);
        }
        return;
    }
    if(start > digits.size() - 1){
        return;
    }

    auto it = m.find(int(digits[start]) - 48);

    if(it != m.end()){
        for(auto x : it->second){
            letter(digits,start + 1,str + x,m);
          }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> m = {
            {2,{'a','b','c'}}, {3,{'d','e','f'}},{4,{'g','h','i'}},
            {5,{'j','k','l'}}, {6,{'m','n','o'}}, {7,{'p','q','r','s'}},
            {8,{'t','u','v'}}, {9,{'w','x','y','z'}}
        };
        letter(digits,0,"",m);
        return ans;
    }
};