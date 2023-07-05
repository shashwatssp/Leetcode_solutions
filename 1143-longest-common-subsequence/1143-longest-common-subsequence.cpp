class Solution {
public:
    int dp[1001][1001];
    
    int solve(int i,int j, int n, int z, string text1, string text2)
    {
    
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=z;j++)
         {
         if(text1[i-1]==text2[j-1])
             dp[i][j] = 1 + dp[i-1][j-1];
             
             dp[i][j] = max(dp[i][j], dp[i-1][j]);
             dp[i][j] = max(dp[i][j], dp[i][j-1]); 
         }
     }
        
        return dp[n][z];
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int z = text2.size();
        
        memset(dp,0,sizeof(dp));
        return solve(0,0,n,z,text1,text2);
    }
};