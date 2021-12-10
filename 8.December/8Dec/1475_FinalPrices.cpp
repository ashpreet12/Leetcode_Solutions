class Solution {
public:

    vector<int> finalPrices(vector<int>& prices) {
        vector<int>finalPrices;

        for(int i = 0; i < prices.size();i++){
            bool flag = false;
            for(int j = i +1; j < prices.size();j++){
                if(prices[j] <= prices[i]){
                    finalPrices.push_back(prices[i] - prices[j]);
                    flag = true;
                    break;
                }
            }
            if(!flag){
                finalPrices.push_back(prices[i]);
            }
        }
        return finalPrices;
    }
};