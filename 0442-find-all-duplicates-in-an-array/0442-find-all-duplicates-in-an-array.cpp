class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        
        int i=0;
        
        while(i<n)
        {
            int pos = nums[i]-1;
            
            if(nums[i]!=nums[pos])
                swap(nums[i],nums[pos]);
            else
                i++;
        }
        
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                ans.push_back(nums[i]);
        
        return ans;
    }
};