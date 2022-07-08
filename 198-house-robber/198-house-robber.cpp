class Solution {
public:
    
    int robans(vector<int>&num)
    {
        int prev = num[0];
        int prev2 =0;
        
        for(int i=1;i<num.size();i++)
        {
            int take = num[i];
            
            if(i>1) take+=prev2;
            
            int ntake = prev;
            
            int cur = max(take,ntake);
            
            prev2 = prev;
            prev =cur;
            
        
        }
        
        return prev;

    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        return robans(nums);
    }
};