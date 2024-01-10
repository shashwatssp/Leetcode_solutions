class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n= nums.size();
        
        int pro=1;
        
        int prev=0;
        
        int ans=0;
        
        for(int next=0;next<n;next++)
        {
            pro*= nums[next];
            
            while(pro>= k && prev<=next)
            {
                pro/= nums[prev];
                prev++;
            }
            
            ans+= (next-prev+1);
        }
        
        return ans;
    }
};