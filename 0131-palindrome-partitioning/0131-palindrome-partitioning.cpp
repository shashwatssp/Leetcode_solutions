class Solution {
public:
    vector<vector<string>>ans;
    bool check(string s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j && s[i]==s[j])
        {
            i++;
            j--;
        }
        
        return (i>=j);
    }
    void solve(int i, string cur, string s, vector<string>temp, int n)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<n;j++)
        {
            cur+=s[j];
            
            if(check(cur))
            {
                temp.push_back(cur);
                solve(j+1,"",s,temp,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        
        vector<string>temp;
        
        solve(0,"",s,temp,n);
        return ans;
    }
};