class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>umap;
        for(auto x : edges)
        {
            vector<int>test=x;
            
            int a = test[0];
            int b = test[1];
            
            umap[a].push_back(b);
            umap[b].push_back(a);
        }
        
        queue<int> q;
        q.push(source);
        
        vector<bool>visited(n+1,false);
        visited[source]=true;
        
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            
            for(auto x : umap[f])
            {
                if(visited[x]==false)
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
            
            if(visited[destination])
                return visited[destination];
        }
        
        return visited[destination];
        
    }
};