class Solution {
public:
    void reverse(string &str){
        int low = 0;
        int high = str.size() - 1;
        
        while(low <= high){
            swap(str[low],str[high]);
            low++;
            high--;
        }
    }
    string reverseWords(string s) {
        string temp;
        string reversed;
        for(auto c : s){
            
            if(c == ' '){
                reverse(temp);
                reversed += temp + " ";
                temp = "";
                continue;
            }
            temp += c;
        }
        reverse(temp);
        reversed += temp;
        return reversed;
    }
};