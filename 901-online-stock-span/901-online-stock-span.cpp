class StockSpanner {
private:
    stack<pair<int, int>> st;
    int counter;
public:
    StockSpanner() {
        counter = -1;
    }
    
    int next(int price) {
        counter++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int res;
        if(!st.empty()) res = counter - st.top().second;
        else res = counter + 1;
        st.push(make_pair(price, counter));
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */