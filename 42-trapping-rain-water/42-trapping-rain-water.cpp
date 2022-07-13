class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int>rm(n),lm(n);
        
        lm[0]=height[0];
        for(int i=1;i<n;i++)
        lm[i]= max(height[i],lm[i-1]);
            
        rm[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        rm[i]= max(height[i],rm[i+1]);
        
        int ans = 0;
        
        
        for(int i=0;i<n;i++)
      ans+=(min(lm[i],rm[i])-height[i]);
        
        return ans;
        
    }
};