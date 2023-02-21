class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>waitingDays(n,0);
        stack<int>s;
        
        for(int idx = 0; idx < n;idx++){
            while(!s.empty() && temperatures[s.top()] < temperatures[idx]){
                waitingDays[s.top()] = idx - s.top();
                s.pop();
            }
            s.push(idx);
        }
        return waitingDays;
    }
};