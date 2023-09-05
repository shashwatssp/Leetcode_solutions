class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int count=0;
        
        for(int i=0;i<n;i++) count+= matrix[i][m-1];
        for(int j=0;j<m-1;j++) count+= matrix[n-1][j];
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {   
                if(matrix[i][j])
                matrix[i][j]+= min(matrix[i+1][j+1],min(matrix[i+1][j], matrix[i][j+1]));
                count+= matrix[i][j];
            }
        }
        
        return count;

    }
};