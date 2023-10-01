class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        
        int ans=0;
        int n = nums.size();
        
        for(int j=n-1;j>0;j--)
        {
        for(int i=0;i<j;i++)
        {
            if(nums[i]+nums[j]<target) ans++;
        }
        }
        
        return ans;
    }
};