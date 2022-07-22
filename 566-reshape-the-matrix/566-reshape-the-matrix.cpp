class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        int n= mat.size();
        int m=mat[0].size();
        
        if(n*m != r*c)
        return mat;
        
        vector<int>temp;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
        {
         temp.push_back(mat[i][j]);
         cnt++;
         
         if(cnt==c)
         {
         ans.push_back(temp);
         cnt=0;
          temp.clear();
         }
        }
        }
        
        return ans;
    }
};