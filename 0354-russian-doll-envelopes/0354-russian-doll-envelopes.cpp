class Solution {
public:
    static bool comp(const vector<int> &p1, vector<int> &p2)
    {
        if(p1[0]==p2[0]) return p2[1]<p1[1];
        else
        return p1[0]<p2[0];

    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(),envelopes.end(),comp);
       vector<int>ans;
       
        for(int i=0;i<envelopes.size();i++)
        {
            
            if(ans.size()==0)
            ans.push_back(envelopes[i][1]);
            else
            {   
                if(envelopes[i][1]>ans.back())
                ans.push_back(envelopes[i][1]);
                else
                {
                  int lb = lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                  ans[lb] = envelopes[i][1];   
                }
                
            }
        }
        
        return ans.size();
    }
};