class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {   
        
        queue<pair<int,int>>q;
        q.push({0,-1});
        
        vector<int>red[n],blue[n];
        
        for(auto it: redEdges)
            red[it[0]].push_back(it[1]);
        
        for(auto it: blueEdges)
            blue[it[0]].push_back(it[1]);
        
        vector<int>answer(n,INT_MAX);
        
        
        int ans=0;
        
        
        map<vector<int>,int>vis;
        
        while(q.size())
        {
            int sz = q.size();
            
            while(sz--)
            {
                
            int x = q.front().first;
            int y = q.front().second;
            q.pop(); 
                
            if(answer[x]!=INT_MAX && vis[{x,y,ans}]) continue;
            vis[{x,y,ans}]=1;
                
            answer[x] = min(answer[x],ans);   
                
                
                
            if(y!=1)
            {
                for(auto it : red[x])
                 q.push({it,1});
            }
                
            if(y!=2)
            {
                for(auto it: blue[x])
                q.push({it,2});    
            }
   
            }
            
            ans++;
            
            if(ans>(2*n))
                break;
  
        }
        
        for(int i=0;i<n;i++) if(answer[i]==INT_MAX) answer[i]=-1;
        
        return answer;
    }
};