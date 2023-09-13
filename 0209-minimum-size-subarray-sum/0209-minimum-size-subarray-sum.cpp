class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0;
        int n = nums.size();
        
        int mn = n+1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            while(sum>=target)
            {
                mn = min(mn, i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        
        if(mn==n+1) return 0;
        else return mn;
        
        
    }
};