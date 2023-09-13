class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>map;
        map[0]=1;
        
        int sum=0;
        int ans=0;
        
        for(auto it: nums)
        {
            sum+=it;
            ans+=map[sum-k];
            map[sum]++;
        }
     
        return ans;
    }
};