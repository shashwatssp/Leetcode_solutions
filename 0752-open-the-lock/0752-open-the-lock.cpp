class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string init = "0000";
        map<string,int>map,vis;
                for(auto it: deadends)
                map[it]++;
        
        
        
    queue<string>q;
        q.push(init);
        int ans=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string top = q.front();
                q.pop();
                
                if(vis[top]==1) continue;
                else vis[top]=1;
                
                if(top==target)
                    return ans;
                

                    if(map[top]) continue;
            
            
                for(int i=0;i<top.size();i++)
                {
                 string temp = top;
                 
                    if(top[i]>'0' && top[i]<'9')
                    {
                        string t1 = top;
                        string t2 = top;
                        t1[i] = t1[i]+1;
                        t2[i] = t2[i]-1;
                        
                        if(vis[t1]==0)
                        q.push(t1);
                        if(vis[t2]==0)
                        q.push(t2);
                    }
                    else  if(top[i]=='0')
                    {
                        string t1 = top;
                        string t2 = top;
                        t1[i] = '1';
                        t2[i] = '9';
                        if(vis[t1]==0)
                        q.push(t1);
                        if(vis[t2]==0)
                        q.push(t2);
                    }
                    else 
                    {
                        string t1 = top;
                        string t2 = top;
                        t1[i] = '8';
                        t2[i] = '0';
                        if(vis[t1]==0)
                        q.push(t1);
                        if(vis[t2]==0)
                        q.push(t2);
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};