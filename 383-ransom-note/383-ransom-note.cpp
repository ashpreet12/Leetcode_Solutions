class Solution {
public:
    unordered_map<char,int> createMap(string str){
        unordered_map<char,int> m;
        for(auto c : str){
            m[c]++;
        }
        return m;
    }
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> m1 = createMap(ransomNote);
        unordered_map<char,int> m2 = createMap(magazine);
        
        for(auto x : m1){
            if(m2.find(x.first) == m2.end() || x.second > m2[x.first]){
                return false;
            }
        }
        return true;
        
    }
};