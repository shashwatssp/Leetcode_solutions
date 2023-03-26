class Solution {
public:
    int compress(vector<char>& chars) {
      int x=1;
        chars.push_back('!');
        vector<char>ans;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==chars[i-1])
            {
              x++;  
            }else 
            {
              ans.push_back(chars[i-1]);
                if(x!=1)
                {   
                    string a = to_string(x);
                    for(char it: a)
                        ans.push_back(it);
                    x=1;
                }
               }
            }
        
        for(int i=0;i<chars.size();i++)
        {
            if(i<ans.size())
                chars[i]=ans[i];
            else
                chars.pop_back();
        }
        return ans.size();
    }
};