class Solution {
public:
    bool isOperator(string c){
        return c == "+" || c == "-" || c == "*" || c == "/";
    }
    int calculateAnswer(int num1,int num2, string operation){
        if(operation == "+"){
            return num1 + num2;
        }else if(operation == "-"){
            return num2 - num1;
        }else if(operation == "*"){
            return num1 * num2;
        }else{
            return num2 / num1;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token : tokens){
            if(isOperator(token)){
                int first = s.top();
                s.pop();
                int second = s.top();
                s.pop();
                int answer = calculateAnswer(first,second,token);
                s.push(answer);
            }else{
                s.push(stoi(token));
            }
        }
     return s.top();
    }
};