class Solution {
    
    
public:
    
   bool isVal(int i, int j, int n, int m, vector<vector<char>>&grid)
    {
    if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1')
        return true;
       
       return false;
    }
    
   void dfsrec(int i, int j, int n, int m , vector<vector<char>>&grid)
    {
        grid[i][j]='0';
        
        if(isVal(i+1,j,n,m,grid))
           dfsrec(i+1,j,n,m,grid);
           
           if(isVal(i-1,j,n,m,grid))
               dfsrec(i-1,j,n,m,grid);
              
              if(isVal(i,j+1,n,m,grid))
                  dfsrec(i,j+1,n,m,grid);
                 
                 if(isVal(i,j-1,n,m,grid))
                     dfsrec(i,j-1,n,m,grid);
           
    }
    int numIslands(vector<vector<char>>& grid) {
        
        
        int ans=0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                ans++;
                dfsrec(i,j,n,m,grid);
            }
        }
        }
        return ans;
        
    }
};