class Solution {
public:
    int dp[350][5500];
    int solve(int i,int amount, vector<int>& coins, int n)
    {   
        if(amount==0) return 1; 
        if(amount<0 || i==n) return 0;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int ans1 = solve(i,amount-coins[i],coins,n);
        int ans2 = solve(i+1,amount,coins,n);
        
        return dp[i][amount]= ans1+ans2;
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins,n);
    }
};