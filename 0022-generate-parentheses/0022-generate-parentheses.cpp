class Solution {
public:
    vector<string>ans;
    void solve(int idx, int open, int close, int n, string s)
    {
        if(idx>2*n || close>open || open>n) return;
        
        if(idx==2*n)
        {
            if(open==close)
                ans.push_back(s);
            
            return;
        }
        
        
        solve(idx+1,open+1,close,n,s+"(");
        solve(idx+1,open,close+1,n,s+")");
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,0,n,"");
        return ans;
    }
};