class Solution {
public:
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long int dp[2002] = {0};
        dp[1]=1;
        long long int secret=0;
        for(int i=2;i<=n;i++)
        {   
            secret+= (dp[max(i-delay,0)] - dp[(max(i-forget,0))] + mod)%mod;
            dp[i] = secret;
        }
        
        secret=0;
        for(int i= n-forget+1; i<=n; i++)
            secret+=dp[i];
        
        secret%=mod;
        return (int)secret;
    }
};