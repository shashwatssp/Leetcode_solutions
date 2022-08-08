class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    map<int,int> mp;
    int ans=0;
    int cur=0;
    mp[cur]++;
    for(int i=0;i<nums.size();i++)
    {
        cur+=nums[i];
        ans+=mp[cur-k];
        mp[cur]++;
    }
        return ans;
    }
};