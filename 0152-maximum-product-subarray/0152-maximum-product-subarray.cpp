class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pre[n];
        int suff[n];
        
        for(int i=0;i<n;i++) pre[i]=0,suff[i]=0;
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            pre[i]=nums[i]* pre[i-1];
            
            if(pre[i-1]==0) pre[i] = nums[i];
        }
        for(int i=n-2;i>=0;i--) 
        {
            suff[i]= nums[i]* suff[i+1];
            
            if(suff[i+1]==0)
            suff[i]=nums[i];    
        }
        
        int ans = pre[n-1];
        
        for(int i=0;i<n;i++)
        {   
            if(i>0)
            ans= max(ans,pre[i-1]);
            if(i<n-1)
            ans= max(ans,suff[i+1]);
            
            ans = max(ans, nums[i]);
            // cout<<pre[i]<<" "<<suff[i]<<endl;
        }
        
        
        return ans;
    }
};