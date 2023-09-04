class Solution {
public:
   void solve(int i,vector<int>& nums, int n, vector<vector<int>>& ans, vector<int>temp)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(i+1,nums,n,ans,temp);
        temp.pop_back();
        solve(i+1,nums,n,ans,temp); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int>temp;
        solve(0,nums,n,ans,temp);
        return ans;
    }
};