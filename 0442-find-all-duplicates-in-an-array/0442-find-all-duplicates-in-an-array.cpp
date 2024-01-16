class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            int x = nums[i]-1;
            
            if(nums[i]!=nums[x])
                swap(nums[i--],nums[x]);
        }
        
        for(int i=0;i<n;i++)
        {
        if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        
        
        return ans;
    }
};