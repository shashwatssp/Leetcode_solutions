class Solution {
public:
    int dp[305][305];
    int solve(vector<int>&nums, int l, int r)
    {
        if(l>r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans=0;
        
        for(int i=l+1;i<r;i++)
        {  
           int val = nums[l]*nums[i]*nums[r] + solve(nums,l,i)+ solve(nums,i,r);
           ans = max(ans,val ); 
        }
        
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
          vector<int>final;
          final.push_back(1);
          for(auto it: nums) final.push_back(it);
          final.push_back(1);
          memset(dp,-1,sizeof(dp));
        
          int i=0;
          int j= final.size();
        
          return solve(final,i,j-1);
    }
};