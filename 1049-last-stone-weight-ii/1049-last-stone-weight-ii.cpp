class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum=0;
        for(auto it: stones) sum+=it;
        
        int dp[n+1][sum+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                
                if(j>=stones[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j-stones[i-1]];
            }
        }
        
        for(int i=sum/2;i>=0;i--)
            if(dp[n][i])
                return sum-2*i;
        
        return sum;
    }
};