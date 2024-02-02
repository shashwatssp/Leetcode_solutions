class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  
  int i=0,j=0;
  
  vector<int> ans;
  
  map<pair<int,int>,int>vis;
  
  while(i<n && j<m)
  {
    while(j<m && !vis[{i,j}])
    {
      vis[{i,j}]=1;
      ans.push_back(matrix[i][j++]);
    }
    
    j--;
    i++;
    
    while(i<n && !vis[{i,j}])
    {
      vis[{i,j}]=1;
      ans.push_back(matrix[i++][j]);
    }
    
    i--;
    j--;
    
    while(j>=0 && !vis[{i,j}])
    {
      vis[{i,j}]=1;
      ans.push_back(matrix[i][j--]);
    }
    
    j++;
    i--;
    
    while(i>=0 && !vis[{i,j}])
    {
      vis[{i,j}]=1;
      ans.push_back(matrix[i--][j]);
    }
    i++;
    j++;
      
    if(vis[{i,j}])break;   
  }
        
    
  
  return ans;  

    }
};