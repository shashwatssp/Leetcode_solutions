class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
              {
              
              int x = INT_MAX;
              
              if(i-1>=0)
                  x = grid[i-1][j];
              if(j-1>=0)
                  x = min(x, grid[i][j-1]);
               
              if(x!=INT_MAX)
               grid[i][j]+=x;
              
            
                   
              }
          
      }
        
     return grid[n-1][m-1];

    }
};