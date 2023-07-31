class Solution {
public:
    int dp[510][510];
    int n=0;
    int m=0;
    int solve(string word1, string word2, int n, int m)
    {  
    dp[0][0]=0;
        
    for(int i=1;i<=n;i++)dp[i][0]=i;
    for(int j=1;j<=m;j++)dp[0][j]=j;
    
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1]) dp[i][j] =dp[i-1][j-1];
                else dp[i][j] = 1+ min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
         memset(dp,-1,sizeof(dp));
         n= word1.size();
         m= word2.size();
         return solve(word1,word2,n,m); 
    }
};