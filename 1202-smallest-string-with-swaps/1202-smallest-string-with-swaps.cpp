class Solution {
public:
    
    map<int, int> vis;
    
    void dfs(int i, string &s, vector<int> &temp, map<int, int> &vis, string &x, vector<vector<int>> &adj)
    {   
        x += s[i];
        temp.push_back(i);
        vis[i] = 1;
        
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it, s, temp, vis, x, adj);  // Change i to it here
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        
        int n = s.size();
        
        vector<vector<int>> adj(n, vector<int>());
        
        for (auto it : pairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                
                string x = "";
                vector<int> temp;
                
                dfs(i, s, temp, vis, x, adj);
                
                sort(x.begin(), x.end());
                sort(temp.begin(),temp.end());
                
                for (int i = 0; i < temp.size(); i++)
                    s[temp[i]] = x[i];
            }
        }
        
        return s;
    }
};
