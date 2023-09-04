class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> ans;
      
        for(auto it : nums)
        {
            if(ans.size()==0 || ans.back()<it)
                ans.push_back(it);
            else
            {
                int lb = lower_bound(ans.begin(),ans.end(),it)-ans.begin();
                ans[lb]=it;
            }
        }
    return ans.size();
    }
};