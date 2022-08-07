class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    map<char,int> mp;
    for(auto it : tasks) mp[it]++;
        
    priority_queue<int> pq;
        
    for(auto it : mp) pq.push(it.second);
    int result=0;
    while(!pq.empty())
    {
        vector<int> temp;
        int time = 0;
        for(int i=0;i<n+1;i++)
        {
         if(!pq.empty())
         {
         temp.push_back(pq.top()-1);
         pq.pop(); 
         time++;
         }

        }
        for(auto it : temp) if(it) pq.push(it);
        result+= (pq.empty()?time:n+1);         
    }
      return result;  
        
    }
};