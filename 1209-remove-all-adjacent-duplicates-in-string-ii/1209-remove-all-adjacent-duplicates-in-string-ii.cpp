class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        
        int cur=1;
        
        for(int i=0;i<n;i++)
        { 
            if(st.size() && st.top().first == s[i])
            {
               cur = st.top().second;
                cur++;
                st.push({s[i],cur});
                if(cur==k)
                {
                    while(cur!=0)
                    {
                        st.pop();
                        cur--;
                    }
                } 
                    
            }
            else
            {
                cur=1;
                st.push({s[i],cur});
            }
                
                
        }
        
       string ans="";
        
        while(st.size())
        {
            ans+= st.top().first;
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};