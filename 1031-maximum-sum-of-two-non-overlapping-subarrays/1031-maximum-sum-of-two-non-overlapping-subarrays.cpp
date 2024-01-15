class Solution {
public:
    int solve(vector<int>& nums, int firstLen, int secondLen, int n)
    {
        int sum_one=0;
        int two_sum=0;
        
        int i=0;
        
        while(i<firstLen)
            sum_one+=nums[i++];
        
        while(i<firstLen+secondLen)
            two_sum+=nums[i++];
        
        int ans = sum_one+two_sum;
        int cur = sum_one;
        
        while(i<n)
        {
            sum_one+= nums[i-secondLen];
            sum_one-= nums[i-secondLen-firstLen];
            
            cur = max(cur,sum_one);
            
            two_sum+= nums[i];
            two_sum-=nums[i-secondLen];
            
            ans = max(ans, cur + two_sum);
            i++;
        }
        
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        return max(solve(nums,firstLen,secondLen,n),solve(nums,secondLen,firstLen,n));
    }
};