class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
       int ans=0;
       int cur=0;
       int prev=0;
       int n = nums.size();
        
       for(int i=2;i<n;i++)
       {
           if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
               cur = prev+1;
           else 
               cur=0;
           
           ans+=cur;
           prev=cur;
       }
        return ans;
    }
};