class Solution {
public:
    void dfs(int i,vector<bool>&vis,vector<vector<int>> &adj,long long &count)
    {
        vis[i] = true;
        count++;
        for(int j=0;j<adj[i].size();j++)
        {
            if(vis[adj[i][j]]==true) continue;
            dfs(adj[i][j],vis,adj,count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);            
        }
        
        long long ans=((long long)n*(n+1))/2;
        
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {   
            
            if(!vis[i])
            {
            long long cnt=0;    
            dfs(i,vis,adj,cnt);
            ans-=(cnt*(cnt+1))/2;                
            }

        }
    return ans;
    }
};