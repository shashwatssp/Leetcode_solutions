class Solution {
public:
    int dp[205][100000];
    bool solve(int i, vector<int>& nums, int sum)
    {   
        if(sum==0) return true;
        if(i==nums.size() || sum<0) return false;
    
        
        if(dp[i][sum]!=-1) return dp[i][sum]==1;
        
        
        
        bool ans1= solve(i+1,nums,sum-nums[i]);
        
        bool ans2= solve(i+1,nums,sum);
        
        if(ans1==true || ans2==true)
        return dp[i][sum] = 1;
        else
        return dp[i][sum]=0;
        
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it: nums) sum+= it;
        
        if(sum%2==1) return false;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,nums,(sum/2));
    }
};