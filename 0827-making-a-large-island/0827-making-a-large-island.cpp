class Solution {
public:
    int size(int i,int j,vector<vector<int>>& grid,int id)
    {
    if(i<0 || i>=grid.size() || j<0 || j>=grid.size() || grid[i][j]!=1) return 0;
    grid[i][j] = id;
    return 1 + size(i+1,j,grid,id) + size(i,j+1,grid,id) + size(i-1,j,grid,id) + size(i,j-1,grid,id);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        map<int,int> label;
        int gp=2;
        
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0; j<grid.size(); j++)
          {
              if(grid[i][j]==1)
              {
                int sz = size(i,j,grid,gp);
                 label[gp]=sz;
                  gp++;
              }
          }
        }
        
        int n = grid.size();
        int ans=1;
        
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0; j<grid.size(); j++)
          {
              int cur=1;
              
              
              if(grid[i][j]==0)
              {
                  set<int>set;
                  
                  if(i+1<n) set.insert(grid[i+1][j]);
                  if(j+1<n) set.insert(grid[i][j+1]);
                  if(i-1>=0) set.insert(grid[i-1][j]);
                  if(j-1>=0) set.insert(grid[i][j-1]);
                  
                  for(auto it : set)
                  {
                    cur+=label[it];  
                  }
                  
                  ans = max(ans,cur);
                  
              }
              else ans = max(ans,label[grid[i][j]]);
          }
        }
        
        return ans;
    }
};