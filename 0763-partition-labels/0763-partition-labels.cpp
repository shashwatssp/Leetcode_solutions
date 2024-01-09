class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26,0);
        int n = s.size();
        
        for(int i=0;i<n;i++)
        v[s[i]-'a'] = i;
        
        vector<int>ans;
        
        int mx=-1;
        
        for(int i=0;i<n;i++)
        {
            mx = max(mx, v[s[i]-'a']);
            
            if(mx==i)
                ans.push_back(i+1);
        }
        
        n = ans.size();
        
        for(int i=n-1;i>0;i--)
            ans[i]-=ans[i-1];
        
        return ans;

    }
};