class Solution {
public:
    int dp[205][205];
    int dir[5] = {-1,0,1,0,-1};
    int solve(vector<vector<int>>& matrix,int i,int j,int n, int m) {
    if(dp[i][j]!=-1) return dp[i][j];
    
        int ans=0;
        
        for(int q=0;q<4;q++)
        {
            int x = i+dir[q];
            int y = j+dir[q+1];
            
            if(x<0 || y<0 || x>=n || y>=m)
            continue;
            
            if(matrix[x][y]<= matrix[i][j])
            continue;    
            
            ans = max(ans, 1+ solve(matrix,x,y,n,m));    
        }
        return dp[i][j] = ans;
  
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               ans = max(ans, solve(matrix,i,j,n,m));
            }
        }
        return ans+1;
    }
};