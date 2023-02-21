class Solution {
public:
    bool isSpace(char c){
        return c == ' ';
    }
    int lengthOfLastWord(string s) {
        int len = s.size();
        int high = len - 1;
        while(high >= 0 && isSpace(s[high])){
            high--;
        }
        int low = high;
        while(low >= 0 && !isSpace(s[low])){
            low--;
        }
        return high - low;
    }
};