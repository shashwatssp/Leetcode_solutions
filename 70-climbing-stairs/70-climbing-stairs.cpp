class Solution {
public:
    int fib(int n ,vector<int>&dp)
    {
        if(n<=1) return dp[n]=1;
        
        
        if(dp[n]!=-1) return dp[n];
        
        dp[n] = fib(n-1,dp) + fib(n-2,dp);
        
        return dp[n];

    }
    vector<int>dp = vector<int>(100,-1);
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
              

};