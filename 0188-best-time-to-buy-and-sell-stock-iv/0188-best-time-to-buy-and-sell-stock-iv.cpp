class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
     if(n<=1 || k==0) return 0;
        k*=2;
        if(k>=n)
        {
            int ans=0;
            for(int i=1;i<n;i++)
                if(prices[i]-prices[i-1]>0) ans+= (prices[i]-prices[i-1]);
            return ans;
        }
        
        int dp[k+1];
        for(int i=0;i<=k;i++)
            if(i%2==0) dp[i]=INT_MIN;
        else dp[i]=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(j==0) dp[j] = max(dp[j],-prices[i]);
                    else if(j%2==0) dp[j] = max(dp[j],dp[j-1]-prices[i]);
                        else dp[j] = max(dp[j],dp[j-1]+prices[i]);
            }
        }
        return dp[k-1];
    }
};