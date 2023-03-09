class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        long long mod = 1e9+7;
        
        priority_queue<pair<long long,long long>>pq;
        vector<long long >dis(n,1e18);
        vector<long long >ways(n,0);
        dis[0]=0;
        ways[0]=1;
        
        pq.push({0,0});
         
        while(!pq.empty())
        {
            long long dist = pq.top().first;
            dist*=-1;
            long long node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                long long adjnode = it.first;
                long long adjdist = it.second;
                
    
                long long newDist = dist+adjdist;
                
                if(newDist==dis[adjnode])
                {
                 ways[adjnode] = ways[adjnode] + ways[node];
                 ways[adjnode]%=mod;   
                }
                else if(newDist<dis[adjnode])
                {
                    dis[adjnode] = newDist;
                    ways[adjnode] = ways[node];
                    newDist*=-1;
                    pq.push({newDist,adjnode});
                }
                    
            }
            
        }
        
       return ways[n-1]%mod; 
    }
};