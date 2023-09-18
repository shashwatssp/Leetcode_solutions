class Solution {
public:
    static bool comp(vector<int> &p1, vector<int>& p2)
    {
        if(p1[0]==p2[0]) return p1[1]>p2[1];
        return p1[0]<p2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        int n = envelopes.size();
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0 || envelopes[i][1]>ans.back())
                ans.push_back(envelopes[i][1]);
            else
            {
                int lb = lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[lb] = envelopes[i][1];
            }
        }
        
        return ans.size();
    }
};