class Solution {
public:
    int dp[100000];
    int n;
    int solve(int i, vector<int>& stoneValue)
    {   
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        
        a = stoneValue[i] - solve(i+1,stoneValue);
        
        if(i<n-1)
        b = stoneValue[i]+stoneValue[i+1] - solve(i+2,stoneValue);
        
        if(i<n-2)
        c = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue);
        
        return dp[i] = max(a,max(b,c));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,stoneValue);
        
        
        if(ans>0)
            return "Alice";
        if(ans<0)
            return "Bob";
        return "Tie";
    }
};