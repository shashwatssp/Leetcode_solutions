class Solution {
public:
    bool solve(int mask,int start,int cur,vector<int>& nums, int k, int req)
    {
        if(k==0) return true;
        if(cur==req) return solve(mask,0,0,nums,k-1,req);
        
        for(int i=start;i<nums.size();i++)
        {
            if( (mask&(1<<i))==0 && cur+nums[i]<=req)
                if(solve(mask|(1<<i), i+1, cur+nums[i], nums, k, req)) return true;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int mask=0;
        int sum=0;
        for(auto it: nums) sum+=it;
        
        if(sum%k || n<k) return false;
        
        int req = sum/k;
        
        return solve(mask,0,0,nums,k,req);
    }
};