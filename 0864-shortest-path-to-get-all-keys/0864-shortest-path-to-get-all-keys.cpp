class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> v1(9,0);
        int count=0;
        
        queue<vector<int> >q;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                {
                    v1[6] = i;
                    v1[7] = j;
                }
                
                if(grid[i][j]>='a' && grid[i][j]<='z')
                count++;
            }
        }
        
        int dir[5] = {0,1,0,-1,0};
        
        q.push(v1);
        
        
        map<vector<int>,int>map;
        
        
        int ans=0;
        
        while(q.size())
        {   
            int sz = q.size();
            
            while(sz--)
            {
            vector<int> v = q.front();
            q.pop();
                
            if(map[v]) continue;
            map[v] = 1;
                
            
            int x = v[6];
            int y = v[7];
            int cnt = v[8];  
                
            if(cnt==count)
            {  
                return ans;
            }
            
            for(int i=0;i<4;i++)
            {
                int x1 = x + dir[i];
                int y1 = y + dir[i+1];
                
                if(x1<0 || y1<0 || x1>=n || y1>=m || grid[x1][y1]=='#') continue;
                
                vector<int> xy = v;
                
                xy[6] = x1;
                xy[7] = y1;
                
                if(grid[x1][y1]>='a' && grid[x1][y1]<='g')
                {
                   int x = grid[x1][y1]-'a';
                   if(v[x]==0)
                   {
                   xy[x]++;
                   xy[8]++;   
                   }

                }
                
                else if(grid[x1][y1]>='A' && grid[x1][y1]<='G')
                {
                    int x = grid[x1][y1]-'A';
                    if(xy[x]==0) continue;
                }
                
                q.push(xy);
                
            }
                     
            }
            
            ans++;               
                
            }
        
        return -1;
    }
};

 // "@...a"
 // ".###A"
 // "b.BCc"