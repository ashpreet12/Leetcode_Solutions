class Solution {
public:
    vector<int> removeLeadingZeroes(vector<int> num){
        int idx = 0;
        while(num[idx] == 0){
            idx++;
        }
        if(idx == 0){
            return num;
        }
        vector<int> vec;
        for(int i = idx; i < num.size();i++){
            vec.push_back(num[i]);
        }
        return vec;
    }
    vector<int> addNum(vector<int> &first, vector<int> &second){
        vector<int> answer(max(first.size(),second.size()) + 1, 0);
        int n = answer.size() - 1;
        int ptr1 = first.size() - 1;
        int ptr2 = second.size() - 1;
        int carry = 0;
        while(ptr1 >= 0 && ptr2 >= 0){
            int calculatedSum = carry + first[ptr1] + second[ptr2];
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr1--;
            ptr2--;
            n--;
        }
       
        while(ptr1 >= 0){
            int calculatedSum = carry + first[ptr1];
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr1--;
            n--;
        }
        
        while(ptr2 >= 0){
            int calculatedSum = carry + second[ptr2];
            answer[n] = calculatedSum % 10;
            carry = calculatedSum / 10;
            ptr2--;
            n--;
        }
        if(carry != 0){
            answer[n] = carry;
        }
        return answer;
    }
    vector<int>digitise(int num){
        vector<int>digits;
        while(num != 0){
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> secondNum = digitise(k);
        vector<int> answer = addNum(num,secondNum);
        return removeLeadingZeroes(answer);
    }
};