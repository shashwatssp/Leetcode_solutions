class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>>final;
        for(int i=0;i<n;i++)
        {
            int m = nums[i].size();
            for(int j=0;j<m;j++)
                final.push_back({nums[i][j], i});
        }
        
        
        sort(final.begin(),final.end());
        
        map<int,int>map;
        vector<int>ans(2,0);
        int unique=0;
        int j=0;
        
        int val=INT_MAX;
        
        for(int i=0;i<final.size();i++)
        {
            if(map[final[i].second]==0)
            unique++;
            
            map[final[i].second]++;
            
            if(unique==n)
            {
                while(map[final[j].second]>1)
                {
                map[final[j].second]-- ;
                j++;
                }
                   if(final[i].first-final[j].first<val)
                {
                    val = final[i].first - final[j].first;
                    ans[0] = final[j].first;
                    ans[1] = final[i].first;
                }
            }
            
        }
        
        return ans;
            

        
    }
};