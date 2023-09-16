class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
         map<int,int>idx;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                st.push(i);
                else if(s[i]==')')
                {
                    if(st.size()) st.pop();
                    else {
                        idx[i]=1;
                    }
                }
        }
        
            while(st.size())
            {
                idx[st.top()]=1;
                st.pop();
            }
            
        
        
        string ans="";
        
        for(auto int i=0;i<n;i++)
        {
            if(idx[i]) continue;
            ans+= s[i];
        }
       
        return ans;
       
    }
};