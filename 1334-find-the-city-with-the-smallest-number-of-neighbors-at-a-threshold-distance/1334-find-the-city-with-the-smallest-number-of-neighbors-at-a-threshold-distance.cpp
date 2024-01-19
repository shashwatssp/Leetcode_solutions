class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        long long int dp[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j) dp[i][j]=0;
                   else  dp[i][j]= (INT_MAX);
        

        
        for(auto it: edges)
        {
            dp[it[0]][it[1]]=it[2];
            dp[it[1]][it[0]]=it[2];
        }
        
      for(int k=0;k<n;k++)  
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        
        int nbr = INT_MAX;
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            
            
            for(int j=0;j<n;j++)
            {
                if(i!=j && dp[i][j]<= distanceThreshold)
                cnt++;    
            }
            
            
            if(cnt<=nbr)
            {
                nbr = cnt;
                ans = i;
            }
        }
        
        return ans;

    }
};