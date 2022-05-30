class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> map;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
        }
        
        for(auto it : map)
        {
            if(it.second> (nums.size())/3)
            {
                ans.push_back(it.first);
             }
        }
        
        return ans;
        
    }
};