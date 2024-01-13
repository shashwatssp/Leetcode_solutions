class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        stack<int>num;
        
        string temp="";
        int nm=0;
        
        for(char c : s)
        {
            if(c==']')
            {
                while(st.size() && st.top()!= '[')
                {
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                
                int t = num.top();
                num.pop();
                
                string f = "";
                
                while(t--)
                {
                    f+=temp;
                }
                temp="";
              
              for(auto it: f)  
              st.push(it);
            }
            else
            {
                if(c>= '0' && c<= '9')
                {
                    nm*=10;
                    nm+= c-'0';
                }
                
                else if(c=='[')
                {
                    num.push(nm);
                    nm=0;
                    st.push(c);
                }
                else
                st.push(c);
                    
            }
        }
        
        string ans="";
        
        while(st.size())
        {   
            ans+= st.top();
            st.pop();
        }
        
        
        reverse(ans.begin(),ans.end());
        ans+= temp;
        
        return ans;
            
    }
};