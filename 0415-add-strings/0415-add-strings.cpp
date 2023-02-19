class Solution {
public:
    int getInt(char c){
        return (int)(c - 48);
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
    string addStrings(string num1, string num2) {
        if(num1 == "0" && num2 == "0"){
            return "0";
        }
        int ptr1 = num1.size() - 1;
        int ptr2 = num2.size() - 1;
        vector<int>answer(num1.size() + num2.size() + 1,0);
        int n = answer.size() - 1;
        int carry = 0;
        
        while(ptr1 >= 0 && ptr2 >= 0){
            int calculatedSum = carry + getInt(num1[ptr1]) + getInt(num2[ptr2]);
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr1--;
            ptr2--;
            n--;
        }
       
        while(ptr1 >= 0){
            int calculatedSum = getInt(num1[ptr1]) + carry;
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr1--;
            n--;
        }
        
        while(ptr2 >= 0){
            int calculatedSum = getInt(num2[ptr2]) + carry;
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr2--;
            n--;
        }
        if(carry != 0){
            answer[n] = carry;
        }
        return removeLeadingZeroes(stringify(answer));
    }
};