class Solution {
public:
    string makeGood(string s) {
       int n = s.size();
       string ans="";
       
        
        for(auto it : s)
        {
            if(ans.size() && (it-'a'==ans.back()-'A' || it-'A' == ans.back()-'a'))
                ans.pop_back();
            else
                ans+= it;
        }
        
        return ans;
       
    }
};