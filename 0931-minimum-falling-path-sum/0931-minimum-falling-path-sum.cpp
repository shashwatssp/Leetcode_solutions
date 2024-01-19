class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        if(n==1) return matrix[0][0];
        
        int ans=INT_MAX;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c1=INT_MAX,c2=INT_MAX,c3=INT_MAX;
                
                if(j-1>=0) c1 = matrix[i-1][j-1];
                           c2 = matrix[i-1][j];
                if(j+1<n) c3 = matrix[i-1][j+1];
                
                int mn = min(c1,c2);
                mn = min(mn,c3);
                
                matrix[i][j]+= mn; 
                
                if(i==n-1) ans = min(ans,matrix[i][j]);
            }
            
            
        }
        
        return ans;
    }
};