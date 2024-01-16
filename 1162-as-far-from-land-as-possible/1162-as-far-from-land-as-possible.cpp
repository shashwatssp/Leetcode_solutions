class Solution {
public:
    bool notvalid(int i, int j, int n, int m)
    {
        return (i<0 || j<0 || i>=n || j>=m);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j])
                    q.push({i,j});
        
        int ans=0;
        map<pair<int,int>,int>vis;
        
        int helper[] = {0,1,0,-1,0};
        
        while(q.size())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(vis[{x,y}] || notvalid(x,y,n,m)) continue;
                
                vis[{x,y}]=1;
                
                for(int i=0;i<4;i++)
                {
                    int x1 = x+helper[i];
                    int y1 = y+helper[i+1];
                    
                    if( notvalid(x1,y1,n,m) || vis[{x1,y1}] || grid[x1][y1] ) continue;
                    q.push({x1,y1});
                    

                    grid[x1][y1] = 1 + grid[x][y];
                    ans = max(ans, grid[x1][y1]);
                }
            }
           
        }

        return ans-1;
    }
};