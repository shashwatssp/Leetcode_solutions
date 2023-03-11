class Solution {
public:
    int maximumGap(vector<int>& nums) {
      
      int n = nums.size();
         if(n<=1) return 0; 
      int mn = INT_MAX;
      int mx = INT_MIN;
      int ans=0;
        
      
        for(auto it : nums)
        {
            mn = min(mn,it);
            mx = max(mx,it);
        }
        
        if(mx==mn) return 0;
        
       int bucketSize = (mx-mn+n-2)/(n-1);
        
        int mnBucket[n];
        int mxBucket[n];
        
        for(int i=0;i<n;i++)
        {
            mnBucket[i]=INT_MAX;
            mxBucket[i]=INT_MIN;
        }
        
        for(int i=0;i<n;i++)
        {
            int index = (nums[i]-mn)/bucketSize;
            mnBucket[index] = min(mnBucket[index],nums[i]);
            mxBucket[index] = max(mxBucket[index],nums[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(mnBucket[i]==INT_MAX) continue;
            ans = max(ans,mnBucket[i]-mn);
            mn = mxBucket[i];
        }
        return ans;
    }
};