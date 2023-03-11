class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            vector<int>sum(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                 sum[k]+=matrix[j][k];
                }
                set<int>set;
                set.insert(0);
                int cur=0;
                for(auto it : sum)
                {
                  cur+=it;
                  
                    auto num = set.lower_bound(cur-k);
                    if(num!=set.end())
                    ans = max(ans, cur- *num);
                    
                    set.insert(cur);
                }
                
                
            }
        }
        return ans;
    }
};