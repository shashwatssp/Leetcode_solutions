class Solution {
public:
    int dp[31][1001];
    long long mod = 1e9+7;
    int solve(int n, int k, int target)
    {
        if(n<0 || target<0 || k<0) return 0;
        if(n==0 && target==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        dp[n][target]=0;
        for(int i=1;i<=k;i++)
        {
            if(i>target) continue;
                
             dp[n][target]+=solve(n-1,k,target-i);
                dp[n][target]%=mod;
            
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};