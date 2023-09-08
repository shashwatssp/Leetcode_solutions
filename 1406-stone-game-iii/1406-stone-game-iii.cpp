class Solution {
public:
    int dp[100000];
    int n;
    int solve(vector<int>& stoneValue)
    {   
        dp[n]=0;
        dp[n+1]=0;
        dp[n+2]=0;
        for(int i=n-1;i>=0;i--)
        {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        
        a = stoneValue[i] - dp[i+1];
        
        if(i<n-1)
        b = stoneValue[i]+stoneValue[i+1] - dp[i+2];
        
        if(i<n-2)
        c = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
        
         dp[i] = max(a,max(b,c));
        }
     return dp[0];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        int ans = solve(stoneValue);
        
        if(ans>0)
            return "Alice";
        if(ans<0)
            return "Bob";
        return "Tie";
    }
};