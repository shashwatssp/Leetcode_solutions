class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>&path,vector<vector<int>>&ans, int source )
    {
        path.push_back(source);
        
        if(source == graph.size()-1)
         ans.push_back(path);
        
        for(auto it : graph[source])
            dfs(graph,path,ans,it);
        
        path.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>raasta;
        vector<vector<int>>ans;
        dfs(graph,raasta,ans,0);
        return ans;
    }
};