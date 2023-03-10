class Solution {
public:

    int kInversePairs(int n, int k) {
        
    int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
    long long mod = 1e9+7;
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=k;j++)
           {   
               int l = min(i-1,j);
               if(j==0) dp[i][j]=1;
               else
               for(int p=0; p<=l;p++)
               {
                 dp[i][j] += dp[i-1][j-p];
                   dp[i][j]%=mod;
               }
           }
       }
        return dp[n][k];
    }
};