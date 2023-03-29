class Solution {
public:
    vector<string>ans;
    string multiplyString(string str,int n,char c){
        for(int i = 0; i < n; i++){
            str += c;
        }
        return str;
    }
    void getParanthesis(int totalBrackets,int open,int close,string str){
        if(open < close){
            return;
        }
        if(open == totalBrackets){
            ans.push_back(multiplyString(str,totalBrackets - close, ')'));
            return;
        }
        getParanthesis(totalBrackets,open + 1, close,str + "(");
        getParanthesis(totalBrackets,open, close + 1,str + ")");
    }
    vector<string> generateParenthesis(int n) {
        getParanthesis(n,0,0,"");
        return ans;
    }
};  