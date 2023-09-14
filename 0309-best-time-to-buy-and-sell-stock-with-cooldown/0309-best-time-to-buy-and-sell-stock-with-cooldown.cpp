class Solution {
public:
    int dp[5005][2][2]; //i, st, cool
    int solve(int st, int i, vector<int>& prices, int n, int cool )
    {
        if(i>=n) return 0;
        if(dp[i][st][cool]!=-1) return dp[i][st][cool];
        
        int ans = solve(st, i+1, prices, n,0);
        
        if(st==0 && cool==0)
        ans = max(ans, -prices[i] + solve(1, i+1, prices, n,0));
        
        if(st==1)
        ans = max(ans, prices[i] + solve(0, i+1, prices,n,1)); 
        
        return dp[i][st][cool]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,prices,n,0);
    }
};