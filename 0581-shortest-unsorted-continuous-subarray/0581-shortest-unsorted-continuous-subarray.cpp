class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>riyal;
        for(auto it: nums) riyal.push_back(it);
        sort(riyal.begin(),riyal.end());
        
        int i=-1;
        int j=-2;
        
        for(int x=0;x<nums.size();x++)
            if(nums[x]!=riyal[x])
            {
                i=x;
                break;
            }
        
            for(int x=nums.size()-1;x>=0;x--)
            if(nums[x]!=riyal[x])
            {
                j=x;
                break;
            }
        
        return j-i+1;
    }
};