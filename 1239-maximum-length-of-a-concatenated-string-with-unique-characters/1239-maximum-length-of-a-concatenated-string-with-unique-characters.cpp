class Solution {
public:
    
    bool check(string s)
    {
        map<char,int> map;
        for(auto it : s)
        {
            map[it]++;
            if(map[it]==2) return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
       vector<string> ans;
       
        for(auto it : arr)
        {
            if(check(it))
            {
                ans.push_back(it);
                
                vector<string> newans;
                
                for(auto zz : ans)
                {
                    
                    string ns = it + zz;
                    
                    if(check(ns))
                        newans.push_back(ns);
                }
                
                for(auto ll : newans) ans.push_back(ll);
                    
            }
        }
        int answ=0;
        
        for(auto it : ans)
        {
         if(answ<it.size())
             answ = it.size();
        }
        return answ;
    }
};