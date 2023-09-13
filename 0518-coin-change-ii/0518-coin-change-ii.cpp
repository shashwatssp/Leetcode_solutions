class Solution {
public:
    int dp[350][5500];
    int solve(int i,int amount, vector<int>& coins, int n)
    {   
       
        if(amount==0) return 1;
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<amount;j++)
            {
                if(j==0)
                dp[i][0] = 1;
                else
                dp[i][j] = 0;    
            }
            
        }
    
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=amount;j++)
            {
           int ans1 = 0;
                if(j-coins[i]>=0)
                ans1 = dp[i][j-coins[i]];
           int ans2 = dp[i+1][j];
           dp[i][j] = ans1+ans2; 
  
            }
        }
        
        
        return dp[0][amount];
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(0,amount,coins,n);
    }
};