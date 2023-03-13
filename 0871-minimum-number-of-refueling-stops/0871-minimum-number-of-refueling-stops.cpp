class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int stops=0;
        
        for(auto it : stations)
        {
            int nxtd = it[0];
            int nxtf = it[1];
            
            while(startFuel<nxtd)
            {
                if(pq.empty())
                    return -1;
                
                int top = pq.top();
                pq.pop();
                startFuel+=top;
                stops++;
            }
            pq.push(nxtf);
        }
        
        
             while(startFuel<target)
            {
                if(pq.empty())
                    return -1;
                
                int top = pq.top();
                pq.pop();
                startFuel+=top;
                stops++;
            }
        
        return stops;
    }
};