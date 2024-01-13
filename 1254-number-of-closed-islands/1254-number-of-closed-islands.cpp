class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m) return true;
        
        if(vis[i][j]) return false;
        vis[i][j]=1;
        
        if(grid[i][j]==1) return false;
        
        bool a = dfs(i+1,j,vis,grid,n,m);
        bool b = dfs(i,j+1,vis,grid,n,m);
        bool c = dfs(i-1,j,vis,grid,n,m);
        bool d = dfs(i,j-1,vis,grid,n,m);
        
        return (a||b||c||d);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                if(grid[i][j]==0 && !vis[i][j])
                ans+=!dfs(i,j,vis,grid,n,m);   
            }
        }
        
        return ans;
    }
};