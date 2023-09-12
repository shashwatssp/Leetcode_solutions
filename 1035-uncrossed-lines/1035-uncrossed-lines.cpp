class Solution {
public:
    int dp[505][550];
    int solve(int i, int n,vector<int>& nums, map<int,vector<int>>&map, int prev)
    {
        if(i==n) return 0;
        
        if(dp[i][prev+5]!=-1) return dp[i][prev+5];
        int ans=0;
        
        if(map[nums[i]].size())
        {   
            int x = lower_bound(map[nums[i]].begin(), map[nums[i]].end(),prev+1)-map[nums[i]].begin();
            if(x!=map[nums[i]].size())
            {
              auto it = map[nums[i]];
              int y = it[x];  
              
              if(y>prev)
              ans = 1 + solve(i+1,n,nums,map,y); 
              
            } 
        }
        
        ans = max(ans,solve(i+1,n,nums,map,prev));
        
        return  dp[i][prev+5]=ans;

    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        map<int,vector<int>>map;
        int n= nums2.size();
        
        for(int i=0;i<n;i++)
            map[nums2[i]].push_back(i);
        
        int m = n;
        n= nums1.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(0,n,nums1,map,-1);
        
    }
};