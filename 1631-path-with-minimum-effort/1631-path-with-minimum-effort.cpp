class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push(make_pair(0,make_pair(0,0)));
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        int ans[rows][cols];
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                ans[i][j]=1e8;
        
        ans[0][0]=0;
        
        while(!pq.empty())
        {

                auto p = pq.top();
                pq.pop();
                
                int x,y,cur;
                x = p.second.first;
                y = p.second.second;
                cur = p.first;
                cur*=-1;
                
                cout<<x<<" "<<y<<endl;
                
                if(x==rows-1 && y==cols-1)
                return cur;
                
                for(int i=0;i<4;i++)
                {
                    int nx = x+dir[i];
                    int ny = y+dir[i+1];
                    
                    if(nx>=rows || nx<0 || ny>= cols || ny <0) continue;
                    
                    int newCur = max(cur, abs(heights[nx][ny]-heights[x][y]));
                    
                    if(newCur<ans[nx][ny])
                    {
                        ans[nx][ny] = newCur;
                        newCur*=-1;
                        pq.push(make_pair(newCur,make_pair(nx,ny)));
                    }
            }
        }
        return 0;
    }
};