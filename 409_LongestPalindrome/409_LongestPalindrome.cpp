class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int> m;
        for(auto c : s){
            m[c]++;
        }
        int maxPalindrome = 0;
        for(auto x : m){
            int count = 0;
            int freq = x.second;
            freq % 2 == 0 ? count += freq : count += freq - (freq % 2);
            maxPalindrome += count;
        }
        return maxPalindrome < s.size() ? maxPalindrome + 1: maxPalindrome;
    }
};