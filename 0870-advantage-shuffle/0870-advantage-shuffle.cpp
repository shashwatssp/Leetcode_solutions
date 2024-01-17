class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        set<int>set;
        map<int,int>map;
        
        for(auto it: nums1)
        {
          set.insert(it);
          map[it]++;  
        }
            
        
        
        vector<int>ans;
        
        for(auto it: nums2)
        {
        if(set.upper_bound(it)!=set.end())
        {
            int x = *set.upper_bound(it);
            ans.push_back(x);
            map[x]--;
            
            if(map[x]==0)
            set.erase(x);
        }
            else
            {
            int x = *set.begin();
            ans.push_back(x);
            map[x]--;
                
            if(map[x]==0)   
            set.erase(x); 
            }
        }
        
        return ans;
    }
};