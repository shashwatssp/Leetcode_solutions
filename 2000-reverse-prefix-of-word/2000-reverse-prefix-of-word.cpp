class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans="";
        
        bool flag = true;
        
        for(auto it: word)
        {
            ans+= it;
            
            if(it==ch && flag)
            {
                reverse(ans.begin(),ans.end());
                flag = false;
            }
                
        }
        
        return ans;
    }
};