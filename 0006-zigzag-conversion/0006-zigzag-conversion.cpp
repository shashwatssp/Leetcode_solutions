class Solution {
public:
    string convert(string s, int numRows) {
      vector<string>v(numRows,"");
        
      int i=0;
      int a=0;
      int b=0;
        
      while(i<s.size())
      {
        for(a=0;a<numRows && i<s.size();a++)
        v[a].push_back(s[i++]);
        
        for(a=numRows-2; a>0 && i<s.size();a--)
        v[a].push_back(s[i++]);    
      } 
        
        string ans="";
        
        for(auto it : v)
        {
            ans+=it;
        }
            
        return ans;
    }
};