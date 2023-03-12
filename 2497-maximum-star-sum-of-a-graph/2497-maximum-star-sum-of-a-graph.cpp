class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>>adj(n);
        int ans=INT_MIN;
        for(auto it : edges)
        {
         adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<vals.size();i++)
        {
            int cur=vals[i];
            
            vector<int>temp;
            
            for(auto it : adj[i])
                temp.push_back(vals[it]);
            
            sort(temp.begin(),temp.end());
            reverse(temp.begin(),temp.end());
            
            int l=k;
            if(temp.size()<k)
                l=temp.size();
            
            for(int j=0;j<l;j++)
                if(temp[j]>0)
                cur+=temp[j];
            
            ans = max(cur,ans);
        }
        return ans;
    }
};