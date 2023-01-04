class Solution {
public:
    vector<string>ans;
    string multiplyString(string str,int num){
        for(int i = 0; i < num;i++){
            str += ")";
        }
        return str;
    }
    void bracket(int totalBrackets,int open,int close,string str){
        if(open < close){
            return;
        }
        if(open == totalBrackets){
            str = multiplyString(str,totalBrackets - close);
            ans.push_back(str);
            return;
        }
        bracket(totalBrackets,open + 1,close,str + "(" );
        bracket(totalBrackets,open,close + 1,str + ")" );
    }
    vector<string> generateParenthesis(int n) {
        bracket(n,0,0,"");
        return ans;
    }
};