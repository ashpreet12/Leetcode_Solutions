class Solution {
public:
    int getSubarrays(vector<int>& arr,int start,int end){
        if(end == arr.size()){
            return 0;
        }
        if(start > end){
            return getSubarrays(arr,0,end + 1);
        }
        int sum = 0;
        if((end - start ) % 2 == 0){
            for(int i = start; i <= end;i++){
                sum += arr[i];
            }
        }
        return sum + getSubarrays(arr,start + 1,end);
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        return getSubarrays(arr,0,0);
    }
};