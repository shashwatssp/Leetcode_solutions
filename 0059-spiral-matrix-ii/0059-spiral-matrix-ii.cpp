class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n));
        int sz = n;
        int num=1;
        
        int i=0;
        int j=0;
        
        int direction [] = {0,1,0,-1,0};
        
        int dir=0;
        map<pair<int,int>,int>vis;
        
        
        while(num<=n*n)
        {
            while(i<sz && j<sz && i>=0 && j>=0 && !vis[{i,j}])
            {   
                ans[i][j] = num;
                vis[{i,j}] = 1;
                
                 i+= direction[dir];
                 j+= direction[dir+1];
                
                num++;  
            }
            
            i-=direction[dir];
            j-=direction[dir+1];
            
            
            dir = (dir+1)%4;
            
            i+=direction[dir];
            j+=direction[dir+1];
        }
        
        return ans;
    }
};