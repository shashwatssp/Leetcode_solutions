class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>map;
        for(int i=0;i<s.size();i++) map[s[i]].push_back(i);
        
        int ans=0;
        for(auto it : words)
        {
            bool found = true;
            int prev=-1;
            string w = it;
            
            for(int i=0;i<w.size();i++)
            {
                vector<int>&c = map[w[i]];
                auto x = upper_bound(c.begin(),c.end(),prev);
                if(x==c.end())
                {
                    found = false;
                    break;
                }
                prev = *x;
            }
            if(found==true) ans++;
        }
        return ans;
    }
};