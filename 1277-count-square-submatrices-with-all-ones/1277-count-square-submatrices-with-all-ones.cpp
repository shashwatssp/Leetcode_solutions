class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
           int count=0;
           int m = matrix.size();
           int n = matrix[0].size();
            for(int i=0;i<m-1;i++)
            count+=(matrix[i][n-1]);
        
            for(int i=0;i<n;i++)
            count+=(matrix[m-1][i]);
        
            
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {  
               if(matrix[i][j]==1) 
               matrix[i][j] =    min(matrix[i+1][j+1],min(matrix[i+1][j],matrix[i][j+1]))+1;
               count+= matrix[i][j]; 
                
            }
        }
                
            return count;
    }
};