class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach=0,i=0,ans=0;
        int sz = nums.size();
        while(reach<n)
        {   
            if(i<sz && reach+1>=nums[i])
            reach+=nums[i++];
            else 
            {
                ans++;
                reach+=(reach+1);
            }
        }
        return ans;
    }
};