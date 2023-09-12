class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        map<pair<int,int>,int>vis;
        priority_queue<pair<int,pair<int,int>>>pq;
        
        int dir[5] = {0,1,0,-1,0};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!(i==0 || i==n-1 || j==0 || j==m-1)) continue;
                
                if(vis[{i,j}]) continue;
                
                vis[{i,j}]=1;
                
                pq.push({-heightMap[i][j],{i,j}});
            }
        }
        
 

        
        int ans=0;
        
        while(pq.size())
        {
          
            int value = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            
            for(int i=0;i<4;i++)
            {
                
               int x1 = x + dir[i];
               int y1 = y + dir[i+1];
                
               if(vis[{x1,y1}]) continue;
                
                if(x1<0 || y1<0 || x1>=n || y1>=m) continue;
                
                
                
               if(heightMap[x][y]>heightMap[x1][y1])
               {
                   ans+= heightMap[x][y] - heightMap[x1][y1];
                   heightMap[x1][y1] = heightMap[x][y];
               }
                
                 pq.push({-heightMap[x1][y1],{x1,y1}});
                 vis[{x1,y1}]=1;
 
            }

        }
        return ans;
    }
};