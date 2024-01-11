class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>temp, int k, int n)
    {
        if(n==0 && k==0)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i>9 || n<0) return;
        
        solve(i+1,temp,k,n);
        temp.push_back(i);
        solve(i+1,temp,k-1,n-i);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1,{},k,n);
        return ans;
    }
};