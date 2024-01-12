class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int prev[n];
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {   
            prev[i]=i;
            dp[i]=1;
            
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {   
                    if(dp[j]+1>dp[i])
                    {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }
                    
                }
            }
        }
    
        
        int mx = *max_element(dp,dp+n);
        
        vector<int>temp;
        
        int i;
        for(i=0;i<n;i++)
        {
            if(dp[i]==mx)
                break;
        }
        
        vector<int>ans;
        
        ans.push_back(nums[i]);
        
        while(prev[i]!=i)
        {
            ans.push_back(nums[prev[i]]);
            i = prev[i];
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};