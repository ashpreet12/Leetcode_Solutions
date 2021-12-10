class Solution {
public:
    vector<int> rev(vector<int>v){
        reverse(v.begin(),v.end());
        return v;
    }
    vector<int> getLengths(vector<int> arr,int target){
        vector<int> minPrefix(arr.size(),arr.size());
        unordered_map<int,int> prefixSum = {{0,-1}};
        int total = 0;

        for(int i = 0; i < arr.size();i++){
            total += arr[i];
            if(i > 0){
                minPrefix[i] = minPrefix[i-1];
            }
            auto it = prefixSum.find(total - target);
            if(it != prefixSum.end()){
                minPrefix[i] = min(minPrefix[i],i - prefixSum[total - target]);
            }
            prefixSum.insert({total,i});
        }
        return minPrefix;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int>minPrefix = getLengths(arr,target);
        vector<int>minSuffix = rev(getLengths(rev(arr),target));
        int minLen = INT_MAX;
        for(int i = 0; i < arr.size() - 1;i++){
            minLen = min(minLen,minPrefix[i] + minSuffix[i+1]);
        }
        return minLen > arr.size() ? -1 : minLen;
    }
};