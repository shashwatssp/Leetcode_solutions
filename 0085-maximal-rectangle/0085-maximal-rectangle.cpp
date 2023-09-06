class Solution {
public:
    int mat[201][201];
    int histogram(int i, int m)
    {   
        vector<int>temp;
        
        for(int j=0;j<m;j++)
        {
            if(mat[i][j])
            {
                if(i>0 && mat[i-1][j])
                mat[i][j]+= mat[i-1][j];
            }
            temp.push_back(mat[i][j]);
            
        }
        
        
        int ans=0;
        
        stack<int>st;
        int ns[m];
        
        st.push(m-1);
        ns[m-1] = m;
        
        for(int x=m-2;x>=0;x--)
        {
            while(st.size() && temp[st.top()]>=temp[x])
                st.pop();
            
            if(st.size())
                ns[x] = st.top();
            else
                ns[x] = m;
            
            st.push(x);

            
        }
        
        
        while(st.size()) st.pop();
        
       int ps[m];
        
        st.push(0);
        ps[0] = -1;
        
        for(int x=1;x<m;x++)
        {
            while(st.size() && temp[st.top()]>=temp[x])
                st.pop();
            
            if(st.size())
                ps[x] = st.top();
            else
                ps[x] = -1;
            
            st.push(x);
        }
        
        for(int j=0;j<m;j++)
        {
            // cout<<temp[j]<<" "<<ns[j]<<" "<<ps[j]<<endl;
            ans = max(ans, (ns[j]-ps[j]-1)*temp[j]);
        }
            
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
            ans = max(ans, histogram(i,m));
        
        return ans;
    }
};