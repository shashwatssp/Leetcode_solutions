class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>& candidates, int target, int n, vector<int>temp) {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(target<0) return;
            

        
        if(i==n) return;
        
        temp.push_back(candidates[i]);
        
       
        solve(i,candidates,target-candidates[i],n,temp);
        temp.pop_back();
        
        solve(i+1,candidates,target,n,temp); 
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       int n = candidates.size();
        vector<int>temp;
       solve(0,candidates,target,n,temp);
        return ans;
    }
};