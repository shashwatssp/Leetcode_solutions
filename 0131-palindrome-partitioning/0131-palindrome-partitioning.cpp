class Solution {
public:
    void help(vector<vector<string>> &ans,vector<string> &cur, string s)
    {
    if(s.size()==0)
    {
        ans.push_back(cur);
        return;
    }
       
        for(int i=0;i<s.size();i++)
        {
            string a = s.substr(0,i+1);
            
            cout<<a<<endl;
            
            if(check(a))
            {
                cur.push_back(a);
                help(ans,cur,s.substr(i+1));
                cur.pop_back();
            }
        }
        
        
    }
    
    bool check(string s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
        if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>cur;
    help(ans,cur,s);
    return ans;    
    }
};