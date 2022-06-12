class Solution {
public:
    
    void dfs(vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&ans, int source)
    {
        path.push_back(source);
        
        if(source==graph.size()-1)
            ans.push_back(path);
        else
        {
         for(auto x : graph[source])
             dfs(graph,path,ans,x);
        }
        path.pop_back();

    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path;
        vector<vector<int>> ans;
        
        dfs(graph,path,ans,0);
        
        return ans;
        
    }
};