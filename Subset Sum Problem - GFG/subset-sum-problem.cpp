//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetPossible(int index, int currentSum, vector<int>arr, int requiredSum, vector<vector<int>> &dp) {
        if(currentSum == requiredSum) {
            return true;
        }
        if(index >= arr.size()) {
            return false;
        }
        
        if(dp[index][currentSum] != -1){
            return dp[index][currentSum];
        }
        dp[index][currentSum] = isSubsetPossible(index + 1, currentSum + arr[index], arr, requiredSum, dp) || 
            isSubsetPossible(index + 1, currentSum , arr, requiredSum, dp);
        
        return dp[index][currentSum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size(), vector<int>(2 * sum + 1, -1));
        return isSubsetPossible(0, 0, arr, sum, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends