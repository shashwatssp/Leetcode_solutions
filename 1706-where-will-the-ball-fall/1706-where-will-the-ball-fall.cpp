class Solution {
public:
    int n,m, dp[105][105];
    
    bool ok(int i, int j)
    {
        return (i>-1 && j>-1 && i<n && j<m)?true:false;
    }
    
    int find(int i, int j, vector<vector<int>>&grid)
    {
        if(i==n) return j;
        
        if(ok(i,j))
        {
            if(grid[i][j]==1 && ok(i,j+1) && grid[i][j+1]==1)
            {
                if(dp[i+1][j+1] != -2) return dp[i+1][j+1];
                else return dp[i+1][j+1] = find(i+1,j+1,grid);
            }
            
            if(grid[i][j]==-1 && ok(i,j-1) && grid[i][j-1]==-1)
                if(dp[i+1][j-1] != -2) return dp[i+1][j-1];
                else return dp[i+1][j-1] = find(i+1,j-1,grid);

        }
        
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        
        for(int i=0;i<105;i++)
            for(int j=0;j<105;j++)
                dp[i][j]=-2;
        
        vector<int> ans;
        
        for(int i=0;i<m;i++)
            ans.push_back(find(0,i,grid));
        
        return ans;       
    }
};