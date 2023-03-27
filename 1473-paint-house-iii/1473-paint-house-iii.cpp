class Solution {
public:
    int mx = 1e9;
    int dp[102][102][102];
    int solve(int idx,int target,int pc,vector<int>& houses, vector<vector<int>>& cost, int n )
    {
        if(target<0) return mx;
        if(idx>=houses.size())
        {
            if(target==0) return 0;
            return mx;
        }
        
        if(dp[idx][target][pc]!=-1) return dp[idx][target][pc];
        
        if(houses[idx]!=0)
        {
            if(houses[idx]!=pc)
                target-=1;
            return solve(idx+1,target,houses[idx],houses,cost,n);
        }
        else
        {   
            int ans = mx;
            for(int i=1;i<=n;i++)
            {
                if(i==pc)
                    ans = min(ans, cost[idx][i-1] + solve(idx+1,target,i,houses,cost,n));
                else
                    ans = min(ans, cost[idx][i-1] + solve(idx+1,target-1,i,houses,cost,n));
            }
            return dp[idx][target][pc] = ans;
        }  
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,target,0,houses,cost,n);
        if(ans==mx) ans=-1;
        return ans;
    }
};