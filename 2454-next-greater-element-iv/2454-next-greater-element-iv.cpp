class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
            v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        
        set<int>set;
        
        vector<int>ans(n,-1);
        
        for(int j=n-1;j>=0;j--)
        {
            int val = v[j].first;
            
            vector<int>temp;
            
            while(j>=0 && v[j].first==val)
            {
                auto x = set.upper_bound(v[j].second);
                
                
                if(x!=set.end())
                {
                    x++;
                    if(x!=set.end())
                    {
                        ans[v[j].second] = nums[*x];
                        // cout<<v[j].second<<" "<<nums[*x]<<endl;
                    }
                }
                
                temp.push_back(v[j].second);
                j--;
            }
            j++;
            
            for(auto it: temp)
            set.insert(it);
        }
        
        return ans;
    }
};