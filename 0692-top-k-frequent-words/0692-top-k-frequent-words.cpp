class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
     map<string,int>map1;
     for(auto it: words) map1[it]++;
        
    map<int,vector<string>>map2;
        
      for(auto it: map1)
      map2[it.second].push_back(it.first);
        
     for(auto &it: map2)
         sort(it.second.begin(),it.second.end());
    
        priority_queue< pair< int,vector<string> >> pq;
        
     for(auto it: map2)
        pq.push(it);
        
        vector<string>ans;
        
        while(pq.size())
        {
            auto x = pq.top().second;
            pq.pop();
            
            for(auto it: x)
            {
                ans.push_back(it);
                k--;
                
                if(k==0)
                return ans;
            }
        }
        
        return ans;
        
    }
};