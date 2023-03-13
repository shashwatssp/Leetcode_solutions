class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmin=0;
        int minsf=INT_MAX;
        
        int curmax=0;
        int maxsf=INT_MIN;
        
        int total=0;
        
        for(auto it : nums)
        {
            curmin = min(curmin+it,it);
            minsf = min(minsf,curmin);
            
            curmax = max(curmax+it,it);
            maxsf= max(maxsf,curmax);
            
            total+=it;
        }
        
        if(maxsf>0)
            return max(maxsf, total - minsf);
        else return maxsf;
        
    }
};