class MinStack {
public:
    stack<int> actual;
    stack<int> minm;
    MinStack() {   
    }
    void push(int val) {
        //ACTUAL STACK
        actual.push(val);
        
        //MIN STACK
        if(minm.empty()){
            minm.push(val);
        }else{
            minm.push(min(minm.top(),val));
        }
    }
    
    void pop() {
        
        actual.pop();
        minm.pop();
    }
    
    int top() {
        return actual.top();
    }
    
    int getMin() {
        return minm.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */