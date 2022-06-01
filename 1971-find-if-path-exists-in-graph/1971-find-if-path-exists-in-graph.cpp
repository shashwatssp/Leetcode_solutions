class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> umap;
        for(auto x : edges)
        {
            vector<int>temp = x;
        int a = temp[0];
        int b = temp[1];
            umap[a].push_back(b);
            umap[b].push_back(a);
        
        }
        
        queue<int> q;
        vector<bool>visited(n+1,false);
        visited[source]=true;
        q.push(source);
        
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
        }
        
        return visited[destination];
        
    }
};