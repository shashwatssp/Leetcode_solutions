class Solution {
public:
    vector<vector<int>>adj;
    map<int,int>vis;
    
    bool check(int node, int col)
    {
        vis[node] = col;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(!check(it,3-col)) return false;
            }
            else
            {
                if(vis[it]==col) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n+2);
        for(int i=0;i<=n+2;i++) vis[i]=0;
        
        for(auto it: dislikes)
        {
            int x = it[0];
            int y = it[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 && !check(i,1))
                return false;
        }
        return true;
    }
};