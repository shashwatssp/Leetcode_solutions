class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<int,int>gs;
        long long ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int g1 = __gcd(nums[i],k);
            
            for(auto it : gs)
            {
                if(((long long)g1 * __gcd(it.first,k))%k==0)
                    ans+=it.second;
            }
            gs[g1]++;
        }
        return ans;
    }
};