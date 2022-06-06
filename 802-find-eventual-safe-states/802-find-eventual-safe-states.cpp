class Solution {
public:
   
    
    bool dfs(int s , vector<bool>&visited, vector<bool>&dfsvisited , vector<bool>&present_cycle, vector<vector<int>>&graph)
    {
        dfsvisited[s] = true;
        visited[s]= true;
        
        vector<int> adj = graph[s];
        
        for(auto x : adj)
        {
            if(!visited[x])
            {
                if(dfs(x,visited,dfsvisited,present_cycle,graph))
                {
                return present_cycle[s] = true;
                }
            }
            else if (visited[x] && dfsvisited[x])
                return present_cycle[s] = true;
        }
        
        
        dfsvisited[s]= false;
        return false;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<bool>dfsvisited(n,false);
        vector<bool>present_cycle(n,false);
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
                dfs(i,visited,dfsvisited,present_cycle,graph);
        }
        
        for(int i=0;i<n;i++)
        {
            if(!present_cycle[i])
                ans.push_back(i);
        }
        
        return ans;
        
    }
};