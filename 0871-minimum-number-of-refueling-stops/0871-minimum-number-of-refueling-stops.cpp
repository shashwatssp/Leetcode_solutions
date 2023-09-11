class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       priority_queue<int>pq;
        int n = stations.size();
        int ans=0;
        for(auto it: stations)
        {
            int x = it[0];
            int y = it[1];
            
            while(startFuel<x)
            {
                if(!pq.size()) return -1;
                int a = pq.top();
                pq.pop();
                startFuel+= a;
                ans++;
            }
            
            pq.push(y);
        }
        
            while(startFuel<target)
            {
                if(!pq.size()) return -1;
                int a = pq.top();
                pq.pop();
                startFuel+= a;
                ans++;
            }
        return ans;
    }
};