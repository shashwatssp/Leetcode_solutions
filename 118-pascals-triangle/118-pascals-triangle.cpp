class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        int n = numRows;
        
        vector<vector<int>> ans;
        
        
        
        for(int i=1;i<=n;i++)
        {
            vector<int> temp = vector<int>(i,1);
            
            if(i>=3)
            {
                for(int j=1; j<temp.size()-1;j++)
                {
                temp[j] =ans[ans.size()-1][j-1]+ ans[ans.size()-1][j];
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};