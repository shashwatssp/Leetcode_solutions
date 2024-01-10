class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n,vector<int>());
        
        for(auto it : connections)
        {
            adj[it[0]].push_back(-it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        map<int,int>vis;
        
        int ans=0;
        
        queue<int>q;
        
        q.push(0);
        
        set<int>set;
        
        while(q.size())
        {
            int x = q.front();
            q.pop();
            
            if(vis[x]) continue;
            
            vis[x] = 1;
            
            for(auto it : adj[x])
            {
                if(it<0)
                {
                    int cur = -it;
                    
                    if(!vis[cur])
                    {
                        ans++;
                        set.insert(cur);
                        q.push(cur);
                    }
                }
                else
                {   
                    if(!vis[it])
                    {
                      q.push(it);
                    }
                    
                    
                }
            }
        }
        
        return ans;
    }
};