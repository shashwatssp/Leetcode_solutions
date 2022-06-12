class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size()+1;
        
        vector<int>visited(n+1,0);
        
        for(auto x : edges)
        {
         visited[x[0]]++;
         visited[x[1]]++;
        }
        
        for(int i=1;i<=n;i++)
            if(visited[i]==(n-1))
                return i;
        
        return -1;
        
        
    }
};