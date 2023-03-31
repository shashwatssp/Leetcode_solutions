class Solution {
public:
    int dp[1001][1001];
    int solve(string s, string t, int i, int j)
    {
        if(j<0) return 1;
        if(i<0) return 0;
        
        // cout<<i<<" "<<j<<endl;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
        else return dp[i][j] = solve(s,t,i-1,j);

    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,s.size()-1,t.size()-1);
    }
};