class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it: flights)
            adj[it[0]].push_back({it[1],it[2]});
        
        queue<pair<int,pair<int,int>>>q;
        //stops, dest, cost
        
        vector<int>distance(n+1,INT_MAX);
        
        q.push({0,{src,0}});
        
        while(q.size())
        {
            int stops = q.front().first;
            int dest = q.front().second.first;
            int cost = q.front().second.second;
           
            q.pop();
            
            if(stops>k) continue;
            
            for(auto it: adj[dest])
            {
                int final_dest = it.first;
                int final_cost = cost+it.second;
                
                
                if(distance[final_dest]>final_cost)
                {
                    distance[final_dest] = final_cost;
                    q.push({stops+1,{final_dest,final_cost}});
                }
            }
        }
        
        
        if(distance[dst]==INT_MAX) return -1;
        return distance[dst];
    }
};