class Solution {
public:
    int dp[2002];
    int solve(int target,vector<int>& nums)
    { 
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        dp[target]=0;
        
        for(int i=0;i<nums.size();i++)
            dp[target]+= solve(target-nums[i],nums);
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        return solve(target,nums);
    }
};