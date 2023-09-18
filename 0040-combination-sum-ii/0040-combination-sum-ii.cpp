class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,int n,int target,vector<int>temp,vector<int>& candidates)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(target<0 || i==n) return;
        
        //pick
        temp.push_back(candidates[i]);
        solve(i+1,n,target-candidates[i],temp,candidates);
        temp.pop_back();
        
        //non-pick
        while(i+1<n && candidates[i]==candidates[i+1])i++;
        solve(i+1,n,target,temp,candidates);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,n,target,temp,candidates);
        return ans;
    }
};