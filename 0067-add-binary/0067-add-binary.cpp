class Solution {
public:
    int getInt(char c){
        return (int)(c - 48);
    }
    int convertToBinary(int num){
        return num == 3 ? 11 : num == 2 ? 10 : num;
    }
    string stringify(vector<int>&answer){
        string ans;
        for(auto digit :answer){
            ans += digit + 48;
        }
        return ans;
    }
    string removeLeadingZeroes(string str){
        int n = str.size();
        int idx = 0;
        while(str[idx] == '0'){
            idx++;
        }
        return str.substr(idx, n - idx);
    }
    string addBinary(string a, string b) {
        if(a == "0" && b == "0"){
            return "0";
        }
        int ptr1 = a.size() - 1;
        int ptr2 = b.size() - 1;
        vector<int>answer(a.size() + b.size() + 1,0);
        int n = answer.size() - 1;
        int carry = 0;
        
        while(ptr1 >= 0 && ptr2 >= 0){
            int binarySum = convertToBinary(carry + getInt(a[ptr1]) + getInt(b[ptr2]));
            answer[n] = binarySum % 10;
            carry = binarySum / 10;
            ptr1--;
            ptr2--;
            n--;
        }
        while(ptr1 >= 0){
            int binarySum = convertToBinary(getInt(a[ptr1]) + carry);
            answer[n] = binarySum % 10;
            carry = binarySum / 10;
            ptr1--;
            n--;
        }
        
        while(ptr2 >= 0){
            int binarySum = convertToBinary(getInt(b[ptr2]) + carry);
            answer[n] = binarySum % 10;
            carry = binarySum / 10;
            ptr2--;
            n--;
        }
        
        if(carry != 0){
            answer[n] = carry;
        }
        return removeLeadingZeroes(stringify(answer));
    }
};