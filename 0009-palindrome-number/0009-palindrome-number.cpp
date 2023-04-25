class Solution {
public:
    long long int reverseNum(int num){
        long long int rev = 0;
        while(num != 0){
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }   
        return reverseNum(x) == x;
    }
};