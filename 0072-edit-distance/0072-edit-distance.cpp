class Solution {
public:
    int dp[510][510];
    int n=0;
    int m=0;
    int solve(string word1, string word2, int i, int j)
    {   
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j] = solve(word1,word2,i-1,j-1);
        return dp[i][j] = 1 + min(min(solve(word1,word2,i-1,j),solve(word1,word2,i,j-1)),solve(word1,word2,i-1,j-1));
    }
    int minDistance(string word1, string word2) {
         memset(dp,-1,sizeof(dp));
         n= word1.size();
         m= word2.size();
         return solve(word1,word2,n-1,m-1); 
    }
};