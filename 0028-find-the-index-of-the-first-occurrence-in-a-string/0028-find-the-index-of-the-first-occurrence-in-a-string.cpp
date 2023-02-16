class Solution {
public:

    int strStr(string haystack, string needle) {
        int firstChar = needle[0];
        for(int i = 0; i < haystack.size();i++){
            if(haystack[i] == firstChar){
                string stringToCheck = haystack.substr(i,needle.size());
                if(stringToCheck == needle){
                    return i;
                }
            }
        }
        return -1;
    }
};