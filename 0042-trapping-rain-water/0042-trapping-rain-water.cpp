class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxBefore[n+1];
        int maxAfter[n+1];
        
        int mxb = 0;
        int mxa = 0;
        
        for(int i=0;i<n;i++)
        {   
            maxBefore[i]=mxb;
            mxb = max(mxb,height[i]);
            maxAfter[n-i-1]=mxa;
            mxa = max(mxa, height[n-i-1]);
            
        }
        
        
        int ans=0;
        
        for(int i=0;i<n;i++) 
            if(min(maxBefore[i],maxAfter[i])- height[i]>0)
             ans+=min(maxBefore[i],maxAfter[i])- height[i];
        
         
        
        
        return ans;
    }
};