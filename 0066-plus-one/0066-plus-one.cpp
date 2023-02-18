class Solution {
public:
    bool isOneDigit(int num){
        int digits = 0;
        while(num != 0){
            num /= 10;
            digits++;
            
            if(digits > 1){
                return false;
            }
        }
        return true;
    }
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = -1;
        while(carry != 0 && n > 0){
            int currDigit = digits[n - 1];
            int calculatedSum = currDigit + 1;
            if(isOneDigit(calculatedSum)){
                digits[n - 1] = calculatedSum;
                carry = 0;
            }else{
                digits[n - 1] = calculatedSum % 10;
                carry = 1;
            }
            n--;
        }
        if(carry != 0){
            vector<int> oneAppendedArray;
            oneAppendedArray.push_back(1);
            oneAppendedArray.insert(oneAppendedArray.end(), digits.begin(), digits.end());
            return oneAppendedArray;
        }
        return digits;
    }
};