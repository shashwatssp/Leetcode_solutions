class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {   
            if(preorder[i]==',') continue;
            
            while(i+1<n && preorder[i+1]!=',')i++;
            
            while(st.size() && st.top()=='#' && preorder[i]=='#')
            {
                st.pop();
                
                if(st.empty()) return false;
                
                st.pop();
            }
            
            st.push(preorder[i]);
        }
        
        return (st.size()==1 && st.top()=='#');
    }
};