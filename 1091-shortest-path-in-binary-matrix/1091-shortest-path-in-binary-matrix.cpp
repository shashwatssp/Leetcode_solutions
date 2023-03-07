class Solution {
public:
    
    vector<pair<int,int>> directions;
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        
        int n = grid.size();
        int m = grid[0].size();
        

    if(grid[0][0]==0)
    q.push(make_pair(0,0));
    else return -1;
    
    if(grid[n-1][m-1]==1) return -1;
        
    map<pair<int,int>,int> visited;  
        
        int ans=1;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto top = q.front();
                q.pop();
                
                if(visited[top]==1) continue;
                int x = top.first;
                int y = top.second;
                
                if(x==y && x==n-1) return ans;
                
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                    
                    if(i==0 && j==0) continue;    
                    int x1 = x+i;
                    int y1 = y+j;
                    
                    if(x1>=0 && x1<n && y1>=0 && y1<n && grid[x1][y1]==0)
                    q.push(make_pair(x1,y1));  
                    
                    visited[make_pair(x,y)]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};