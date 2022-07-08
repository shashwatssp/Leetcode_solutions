class Solution {
public:
    
    int mx(vector<int>&num)
    {   
        int n = num.size();
        int prev = num[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++)
        {
            int take = num[i];
            
            if(i>1) take+=prev2;
            
            int nontake =0 + prev;
            
            int cur = max(take,nontake);
            
             prev2=prev;
             prev = cur;

        }
        
        return prev;
        

    }
   long long int rob(vector<int>&nums) {
        
        vector<int>a1,a2;
        
        int n = nums.size();
       
       if(n==1) return nums[0];
        
       for(int i=0;i<n;i++)
       {
       if(i!=0) a1.push_back(nums[i]);
       if(i!=n-1) a2.push_back(nums[i]);
       }
        return max(mx(a1),mx(a2));
        
    }
};