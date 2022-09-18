class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        
        int a = grid.size();
        int b = grid[0].size();
        
        int c = moveCost.size();
        int d = moveCost[0].size();
        
        int dp[a][b];
        
        for(int i=0;i<b;i++) dp[0][i] = 0;
        
        for(int i=1;i<a;i++)
        {
        for(int j=0;j<b;j++)
        {
            int sum = 0;
            
            int cost = INT_MAX;
            
            for(int k = 0; k < b; k++)
            {
                cost = min(cost, dp[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i-1][k]);
            }
            
            //cout<<cost<<endl;
            dp[i][j] = cost;
                
        }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<b;i++)
          ans = min (ans, (grid[a-1][i] + dp[a-1][i]));  
        
        return ans;
    }
};