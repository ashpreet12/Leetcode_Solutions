class Solution {
public:
    int getInt(char c){
        return (int)(c - 48);
    }
    void addLineMultiple(vector<int>&multipliedAnswer,vector<int>&singleLineMultiply){
        int n = multipliedAnswer.size() - 1;
        int carry = 0;
        for(int i = singleLineMultiply.size() - 1; i >= 0 ; i--){
            int calculatedSum = carry + multipliedAnswer[n] + singleLineMultiply[i];
            multipliedAnswer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            n--;
        }
    }
    string stringify(vector<int>&multipliedAnswer){
        string answer;
        for(auto digit :multipliedAnswer){
            answer += digit + 48;
        }
        return answer;
    }
    string removeLeadingZeroes(string str){
        int n = str.size();
        int idx = 0;
        while(str[idx] == '0'){
            idx++;
        }
        return str.substr(idx, n - idx);
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";;
        }
        int len1 = num1.size();
        int len2 = num2.size();
        int multiplyCross = 0;
        vector<int>multipliedAnswer(len1 + len2 + 1,0);
        
        for(int i = len2 - 1; i >= 0;i--){
            int currLength = len1 + 1 + multiplyCross;
            vector<int>singleLineMultiply(currLength,0);
            int carry = 0;
            int currPower = currLength - 1;
            for(int j = len1 - 1; j >= 0;j--){
                int digitMulAns = carry + getInt(num1[j]) * getInt(num2[i]);
                singleLineMultiply[currPower - multiplyCross] = digitMulAns % 10;
                carry = digitMulAns / 10;
                currPower --;
            }
            if(carry != 0){
                singleLineMultiply[currPower - multiplyCross] = carry;
            }
            multiplyCross++;
            addLineMultiple(multipliedAnswer,singleLineMultiply);
        }
        return removeLeadingZeroes(stringify(multipliedAnswer));
    }
};