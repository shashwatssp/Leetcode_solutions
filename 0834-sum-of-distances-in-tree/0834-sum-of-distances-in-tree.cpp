class Solution {
public:
    vector<int> res;
    vector<int> cnt;
    
    vector<int> adj[1000000];
    
   void post(int cur,int pre)
    {
        for(auto it : adj[cur])
        {
            if(it==pre) continue;
            post(it,cur);
            cnt[cur]+=cnt[it];
            res[cur] += res[it]+cnt[it];
        }
        cnt[cur]++;
    }
    
    
    void preorder(int cur,int pre)
    {
        for(auto a : adj[cur])
        {
            if(a==pre) continue;
            res[a] = res[cur] - cnt[a] + cnt.size() - cnt[a];
            
            preorder(a,cur);
        }

    }
    
    
    
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        
        for(auto it : edges)
        {
            int a = it[0];
            int b = it[1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        
        res.resize(n);
        cnt.resize(n);
        
        post(0,-1);
        
        preorder(0,-1);
        
         return res;
       
        
    }

};