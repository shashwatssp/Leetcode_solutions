class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size()==k) return "0";
        
       stack<int>st;
        
        for(int i=0;i<num.size();i++)
        {
            if(st.empty() || num[i]>= st.top())
            st.push(num[i]);
            else
            {
                while(k && st.size() && st.top()> num[i])
                {   
                    st.pop();
                    k--;
                }
                
                st.push(num[i]);
            }     
        }
        
        while(k)
        {
            st.pop();
            k--;
        }
        
        string ans= "";
        
        while(st.size())
        {
            ans+= st.top();
            st.pop();
        }
        
        for(int i= ans.size()-1;i>0;i--)
        if(ans[i]=='0') ans.pop_back();
        else break;
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};