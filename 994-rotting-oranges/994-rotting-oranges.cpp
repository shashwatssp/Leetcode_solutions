class Solution {
public:
    
    bool isValid(int i, int j, int n, int m, vector<vector<int>>&grid)
    {
    if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1)
        return true;
        
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        
        int fresh=0;
        int time=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(grid[i][j]==2)
            {
            // push into queue
                q.push({i,j});
            }
                
            else if(grid[i][j]==1)
                fresh++;
            }
        }
        
        
        // 0 ouput wala case
        if(fresh==0)
            return 0;
        
        //bfs traversal 
        
        while(!q.empty())
        {
        int change=0;
            
        int size_q = q.size();
            
            while(size_q)
            {
        pair<int,int> f = q.front();
            q.pop();
            
            
            int x = f.first;
            int y = f.second;
            
            int ax[4] = {1,-1,0,0};
            int ay[4] = {0,0, 1,-1};
            
            for(int i=0;i<4;i++)
            {
           int x1 = x + ax[i];
           int y1 = y + ay[i];
                
        if(isValid(x1,y1,n,m,grid))
        {
            grid[x1][y1]=2;
            change++;
            q.push({x1,y1});
        }
            }
                
              
                size_q--;
                
                
            }
                
                        if(change) time++;
                
        
        }
        
        
        //-1 output wala case
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(grid[i][j]==1)
            {
            time=0;
                break;
            }

            }
        }
        
        return (time==0)?-1:time;
        
    }
        
        
};