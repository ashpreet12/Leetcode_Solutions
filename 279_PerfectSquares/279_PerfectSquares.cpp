class Solution {
private:
int z = 1e5+2;
const int mod = 1e9+7;
vector <int> dp = vector<int>(z,mod);

public:
    int numSquares(int n) {
    if(n <= 3)
        return n;

    if(dp[n] != mod)
        return dp[n];

    for(int i=1;i*i <=n;i++)
        dp[n] = min(dp[n],1 + numSquares(n-i*i));

    return dp[n];
    }
};