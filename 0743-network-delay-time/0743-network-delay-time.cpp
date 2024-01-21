class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        
       dist[k-1]=0;
        
        map<int,vector<pair<int,int>>>map1;
        
        for(auto it: times)
       map1[it[0]].push_back({it[1],it[2]});
        
        q.push(k);
        
        map<vector<int>,int>vis;
        
        while(q.size())
        {
            int x = q.front();
            q.pop();
            
            if(vis[dist]==2*n) continue;
            
            vis[dist]+=1;
            
            for(auto it: map1[x])
            {
                int to = it.first;
                int weight = it.second;
                
                dist[to-1] =min(dist[to-1], dist[x-1]+ weight);
                q.push(to);
            }
        }
        
        int mx = *max_element(dist.begin(),dist.end());
        
        if(mx==INT_MAX) return -1;
        else return mx;
        
    }
};