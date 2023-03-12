class Solution {
public:
    void dfs(int i, vector<bool>&vis, vector<vector<int>>&adj)
    {
        vis[i]=true;
        for(int j=0;j<adj[i].size();j++)
            if(!vis[adj[i][j]])
                dfs(adj[i][j],vis,adj);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n),ans(n);
        
        for(auto it : edges)
            adj[it[0]].push_back(it[1]);
        
        for(int i=0;i<n;i++)
        {
            vector<bool>vis(n,false);
            dfs(i,vis,adj);
            for(int j=0;j<n;j++)
            {
                if(i!=j && vis[j])
                    ans[j].push_back(i);
            }
        }
        return ans;
    }
};