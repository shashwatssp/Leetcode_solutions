class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[m-1][n-1]) return 0;
        
        int dp[m][n];
        
        int i=0;
        for(i=0;i<m;i++)
           if(!obstacleGrid[i][0]) dp[i][0] = 1;
        else break;
        
        for(int j=i;j<m;j++) dp[j][0] =0;
        
        
                
         i=0;
        for(i=0;i<n;i++)
           if(!obstacleGrid[0][i]) dp[0][i] = 1;
        else break;
        
        
        for(int j=i;j<n;j++) dp[0][j] =0;
        
        cout<<m<<" "<<n<<endl;
        if(m==1 || n==1) return dp[m-1][n-1];
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                cout<<dp[i][j]<<" "; 
                int sum=0;
                
                if(!obstacleGrid[i-1][j]) sum+= dp[i-1][j];
                if(!obstacleGrid[i][j-1]) sum+= dp[i][j-1];
                
                
                dp[i][j] = sum;
            }
        }
        
        return dp[m-1][n-1];
    }
};