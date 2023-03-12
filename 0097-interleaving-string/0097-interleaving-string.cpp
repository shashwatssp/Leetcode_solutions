class Solution {
public:
    bool dp[102][102] = {false};
    bool isInterleave(string s1, string s2, string s3) {
       int a=s1.size();
       int b=s2.size();
       int c=s3.size();
        
        if(a+b!=c) return false;
        
        dp[0][0] = true;
        
        for(int i=1;i<=a;i++) dp[i][0] = dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        for(int i=1;i<=b;i++) dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
              dp[i][j] = (dp[i-1][j]&&(s1[i-1]==s3[i+j-1]))  || ((dp[i][j-1])&&(s2[j-1]==s3[i+j-1]));
            }
        }
        
        
        return dp[a][b];
    }
};