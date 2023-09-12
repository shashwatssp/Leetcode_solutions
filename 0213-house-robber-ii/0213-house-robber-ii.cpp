class Solution {
public:
    int dp[104][104];
    int solve(int i, int prev,vector<int>& nums,int n)
    {
    
        if(i==n) return 0;
    
        if(dp[i][prev+2]!=-1) return dp[i][prev+2];
        
       int ans = solve(i+1,prev,nums,n);
        
        if(i-1!=prev) ans = max(ans, nums[i]+ solve(i+1, i, nums, n));
        return dp[i][prev+2]=ans;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return nums[0];
        
        memset(dp,-1,sizeof(dp));
        
        int left = solve(0,-2,nums,n-1);
        memset(dp,-1,sizeof(dp));
        int right = solve(1,-2,nums,n);
        
        return max(left,right);
    }
};