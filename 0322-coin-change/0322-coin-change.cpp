class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        
        for(int i=1;i<=amount;i++) dp[i] = INT_MAX;
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            for(auto it : coins)
            {
                if(i-it>=0 && dp[i-it]!=INT_MAX)
                    dp[i] =  min(dp[i], dp[i-it]+1);
            }
        
        }
        
        return (dp[amount]!=INT_MAX)?dp[amount]:-1;
    }
};