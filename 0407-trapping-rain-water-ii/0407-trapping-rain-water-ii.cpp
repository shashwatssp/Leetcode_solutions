class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        priority_queue<pair<int,pair<int,int>>>pq;
        int n = heightMap.size();
        int m = heightMap[0].size();
        map<pair<int,int>,int> vis;
        
        int dir[5] = {0,-1,0,1,0};
        
        for(int i=0;i<n;i++)
        {   
            if(vis[{i,0}]==0)
            pq.push({-heightMap[i][0],{i,0}});
            
            if(vis[{i,m-1}]==0)
            pq.push({-heightMap[i][m-1],{i,m-1}});
            
            vis[{i,0}] = 1;
            vis[{i,m-1}] = 1;
            
        }
        
        for(int i=0;i<m;i++)
        {
            if(vis[{0,i}]==0)
            pq.push({-heightMap[0][i],{0,i}});
            
            if(vis[{n-1,i}]==0)
            pq.push({-heightMap[n-1][i],{n-1,i}});
            
            vis[{0,i}] = 1;
            vis[{n-1,i}] = 1;
        }
        

        
        int ans=0;
        
        while(pq.size())
        {
            int value = -1* pq.top().first;
            
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int x1 = x+dir[i];
                int y1 = y+dir[i+1];
                
                
                if(x1<0 || y1<0 || x1>n-1 || y1>m-1) continue;
                
                if(vis[{x1,y1}]) continue;
                
                vis[{x1,y1}] = 1;
                
                
                if(heightMap[x1][y1]<heightMap[x][y])
                {
                    ans+= heightMap[x][y] - heightMap[x1][y1];
                    heightMap[x1][y1] = heightMap[x][y];
                }
                    
                
                int mx = max(heightMap[x][y],heightMap[x1][y1]);
                pq.push({-mx,{x1,y1}});
                
            }
        }
        

        
        return ans;
        
    }
};