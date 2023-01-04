class Solution {
public:
    unordered_map<char,int> getFreq(string str){
        unordered_map<char,int> m;
        for(auto x : str){
            m[x]++;
        }
        return m;
    }
    bool isMatching(unordered_map<char,int> m1,unordered_map<char,int> m2){
        for(auto x : m1){
            if(m2.find(x.first) == m2.end() || m1[x.first] > m2[x.first]){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m = getFreq(chars);
        int count = 0;
        for(auto str : words){
            unordered_map<char,int> s = getFreq(str);
            if(isMatching(s,m)){
                count+=str.length();
            }
        }
        return count;
    }
};