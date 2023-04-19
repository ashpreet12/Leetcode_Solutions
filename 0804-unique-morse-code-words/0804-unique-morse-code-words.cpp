class Solution {
public:
    string transform(string word, vector<string> &codes){
        int ALPHABET_ASCII = 97;
        string transformedStr;
        
        for(auto c : word){
            transformedStr += codes[c - ALPHABET_ASCII];
        }
        return transformedStr;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        
    vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> transformations;
        for(auto word : words){
            transformations.insert(transform(word,codes));
        }
        return transformations.size();
    }
};