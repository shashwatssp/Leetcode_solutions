class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
      int curmin=0;
      int minsf=0;
      int curmax=0;
      int maxsf=0;
      int ans=0;
        
      for(auto it : nums)
      {
          curmin = min(curmin+it,it);
          minsf = min(minsf,curmin);
          
          curmax = max(curmax+it,it);
          maxsf = max(maxsf,curmax);
          
          ans = max(ans,max(abs(curmin),curmax));
          
      }
        return ans;
    }
};