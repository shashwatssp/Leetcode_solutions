class Solution {
public:
    bool match(string &a, string &b)
    {
        if(a.size()!=b.size()) return false;
        vector<char>for_a(26,' '),for_b(26,' ');
        
        int n = a.size();
        
        for(int i=0;i<n;i++)
        {
            if(for_a[a[i]-'a']==' ' && for_b[b[i]-'a']==' ')
            {
                for_a[a[i]-'a'] = b[i];
                for_b[b[i]-'a'] = a[i];
            } 
            else
            {
                if(for_a[a[i]-'a']!=b[i] || for_b[b[i]-'a']!=a[i])
                return false;    
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        for(auto it: words)
        {
            if(match(it,pattern))
                ans.push_back(it);
        }
        
        return ans;
    }
};