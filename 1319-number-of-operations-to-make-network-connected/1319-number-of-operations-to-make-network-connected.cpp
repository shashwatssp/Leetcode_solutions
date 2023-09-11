class Solution {
public:
    vector<int>parent;
    int find(int i)
    {
        if(parent[i]==-1) return i;
        return find(parent[i]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        parent.resize(n,-1);
         
        if(n-sz>1) return -1;
        
        
        for(auto it: connections)
        {
            int x = find(it[0]);
            int y = find(it[1]);
            
            if(x!=y) 
                parent[y]=x;
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            if(parent[i]==-1) ans++;
        
        ans--;
        
        return ans;
  
    }
};