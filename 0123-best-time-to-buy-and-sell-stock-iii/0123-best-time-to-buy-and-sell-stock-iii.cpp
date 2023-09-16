class Solution {
public:
    int dp[1000000][2][2];
    
    int solve(int i, int st, int op, int n, vector<int>&prices)
    {
        if(i==n || op==2) return 0;
        
        if(dp[i][st][op]!=-1) return dp[i][st][op];
        
        int ans = solve(i+1,st,op,n,prices);
        if(st==1)
            ans = max(ans, prices[i]+ solve(i+1, 0, op+1, n, prices));
        
           if(st==0)
            ans = max(ans, -prices[i]+ solve(i+1, 1, op, n, prices));
        
       return dp[i][st][op]= ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,prices);
    }
};