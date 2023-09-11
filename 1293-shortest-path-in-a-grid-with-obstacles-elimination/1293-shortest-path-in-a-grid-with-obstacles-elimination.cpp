class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m][k+1];
        memset(vis,-1,sizeof(vis));
        
        queue<vector<int>>q;
        
        vector<int> temp(3,0);
        
        temp[0]=0;
        temp[1]=0;
        temp[2]=k;
        
        q.push(temp);
        
        
        int ans=0;
        
        while(q.size())
        {
            int sz = q.size();

            while(sz--)
            {
              vector<int> p = q.front();
              q.pop();
                
               
                
              int x = p[0];
              int y = p[1];
              int z = p[2]; 
                
                if(x==n-1 && y==m-1)
                    return ans;
                
                if(x<0 || y<0 || x>=n || y>=m || z<0 ) continue;
                
              
                
                if(vis[x][y][z]==1) continue;
                
                cout<<x<<" "<<y<<" "<<z<<endl;
                
                vis[x][y][z]=1;
                
                if(grid[x][y]==1) z--;
                cout<<grid[x][y]<<endl;
                
                if(z<0) continue;
                
                if(x+1<n && vis[x+1][y][z] != 1)
                q.push({x+1,y,z});
                
                if(y+1<m && vis[x][y+1][z] != 1)
                q.push({x,y+1,z});
                
                if(x-1>=0 && vis[x-1][y][z] != 1)
                q.push({x-1,y,z});
                
                if(y-1>=0 && vis[x][y-1][z] != 1)
                q.push({x,y-1,z});                
            }
            cout<<"-----"<<endl;
            ans++;
        }
        
        return -1;
    }
};