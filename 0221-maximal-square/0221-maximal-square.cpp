class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans=0;
        
        int mat[n][m];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] = matrix[i][j] - '0';
                
                ans = max(ans, mat[i][j]*mat[i][j]);
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {   
                if(mat[i][j]==0) continue;
                
                mat[i][j]+= min(mat[i+1][j], min(mat[i][j+1], mat[i+1][j+1]));
                
                ans = max(ans, (mat[i][j]*(mat[i][j])));
            }
        }
        
        
        return ans;
    }
};