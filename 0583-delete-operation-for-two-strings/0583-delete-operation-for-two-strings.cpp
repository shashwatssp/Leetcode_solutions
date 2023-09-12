class Solution {
public:
    int dp[505][505];
    int solve(int i,int j,int n, int m,string word1, string word2)
    {
        if(i==n && j==m) return 0;
        
        if(i==n) return (m-j);
        if(j==m) return (n-i);
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 1 + solve(i+1,j,n,m,word1,word2);
        ans = min(ans, 1 + solve(i,j+1,n,m,word1,word2));
        
        if(word1[i]==word2[j])
            ans = min(ans,solve(i+1,j+1,n,m,word1,word2));
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,word1,word2);
    }
};