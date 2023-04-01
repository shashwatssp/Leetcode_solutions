class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int,vector<string>>len;
        for(auto it : words)
            len[it.size()].push_back(it);
        int ans=0;
        map<string,int>map;
        
        for(auto it : len)
        {
            for(auto zz : it.second)
            {
              map[zz]=1;
                
              for(int i=0;i<zz.size();i++)
              {
                  string cur = zz.substr(0,i) + zz.substr(i+1);
                  
                      map[zz] = max(map[zz], map[cur]+1);
              }
                ans = max(ans, map[zz]);
            }
        }
        return ans;
    }
};