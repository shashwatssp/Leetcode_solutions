class Solution {
public:
    int minJumps(vector<int>& arr) {
    
        map<int,vector<int>>map;
        
        for(int i=arr.size()-1;i>=0;i--)
        {
           map[arr[i]].push_back(i);
        }
        
            
        
        
        int pos=0;
        int jump=0;
        
        queue<int>q;
        q.push(0);
        set<int>set;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int top = q.front();
                
                q.pop();
                
                if(top==arr.size()-1) return jump;
                
                if(top-1>=0 &&  set.find(top-1)==set.end())
                    q.push(top-1);
                
                   if(top+1>=0 &&  set.find(top+1)==set.end())
                    q.push(top+1);
                
                for(auto it : map[arr[top]])
                {  
                    if(it!=top && set.find(it)==set.end())
                      q.push(it);  
                }
                
                map.erase(arr[top]);
                
                set.insert(top);
            }
            
            jump++;
        }
        return false;
    }
};