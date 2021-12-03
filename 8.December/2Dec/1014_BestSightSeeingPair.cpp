class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int firstPair = values[0];
        int secondPair = INT_MIN;
        int maxPair = INT_MIN;

        for(int i = 1; i < values.size();i++){
            secondPair = values[i] - i;
            maxPair = max(maxPair,firstPair + secondPair);
            firstPair = max(firstPair,values[i] + i);
        }
        return maxPair;
    }
};