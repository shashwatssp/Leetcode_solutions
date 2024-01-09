class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        map<char,int>second;
        
            for(int i=n-1;i>=0;i--)
        {
            if(second[s[i]]) continue;
            second[s[i]]=i;
        }
        
     int mx=-1;
     int prev=0;
     vector<int>ans;
     
        for(int i=0;i<s.size();i++)
        {   
            mx = max(mx, second[s[i]]);
            if(mx==i)
            {   
                ans.push_back(i+1);
            }
        }
        
        for(int i=ans.size()-1;i>0;i--)
        {
            ans[i]-=ans[i-1];
        }
        
     return ans;
    }
};