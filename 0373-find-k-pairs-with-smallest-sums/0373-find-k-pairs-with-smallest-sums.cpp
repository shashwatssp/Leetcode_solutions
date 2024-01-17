class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<pair <int,pair<int,int>> >pq;
        pq.push({-(nums1[0]+nums2[0]),{0,0}});
        
        map<pair<int,int>,int>map;
        
        vector<vector<int>>ans;
        
        while(k)
        {
            auto t = pq.top();
            pq.pop();
             
            int x = t.second.first;
            int y = t.second.second;
            
            if(map[{x,y}]) continue;
            else map[{x,y}]=1;
            
            k--;
            ans.push_back({nums1[x],nums2[y]});
            
            
            if(x+1<n)
                pq.push({-(nums1[x+1]+nums2[y]), {x+1,y}});
            
            if(y+1<m)
                pq.push({-(nums1[x]+nums2[y+1]), {x,y+1}});
        }
        
        return ans;
        
    }
};