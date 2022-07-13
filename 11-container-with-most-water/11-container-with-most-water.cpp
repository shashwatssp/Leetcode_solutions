class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ans = INT_MIN;
        
        while(l<r)
        {
            int lh = height[l];
            int rh = height[r];
            int mh = min(lh,rh);
            
            ans = max(ans, (mh*(r-l)));
            
            if(lh<rh) l++;
            else r--;

        } 
                      
         return ans;            
                      
    }
};