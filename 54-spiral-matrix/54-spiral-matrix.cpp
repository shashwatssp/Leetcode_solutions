class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> ans;
        
       int hs=0, he=m-1, vs=0, ve=n-1;
        
        while(ans.size()!=(n*m))
        {
         int i = vs;
         int j = hs;
            
         while(j<=he)
         ans.push_back(matrix[i][j]), j++;
         j--; i++;
         vs++;
            
        if(ans.size()==(n*m)) break;
            
         while(i<=ve)
         ans.push_back(matrix[i][j]), i++;
         i--;j--;
         he--;
            
        if(ans.size()==(n*m)) break;
            
         while(j>=hs)
         ans.push_back(matrix[i][j]), j--;
         j++; i--;
         ve--;
            
        if(ans.size()==(n*m)) break;
            
         while(i>=vs)
         ans.push_back(matrix[i][j]), i--;
         j++; i--; 
         hs++;
            
        if(ans.size()==(n*m)) break;
   
        }
        
        return ans;
    }
};