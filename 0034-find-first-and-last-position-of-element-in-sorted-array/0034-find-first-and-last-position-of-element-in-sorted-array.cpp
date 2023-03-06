class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans;
        
        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        ans.push_back(lb);
        
        int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        ub--;
        ans.push_back(ub);
        
        vector<int> alt;
        
           if(ub==lb && ub==0)
            {
            alt.push_back(0);
            alt.push_back(0); 
                return alt;
            }
               
        
        if(ub<lb)
        {
            
            alt.push_back(-1);
            alt.push_back(-1);
            return alt;
        }
        
        return ans;
    }
};