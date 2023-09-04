class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int rb[n];
        rb[n-1]=n;
        
        stack<int>st;
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.size())
                rb[i] = st.top();
            else
                rb[i]=n;
            
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        int lb[n];
        lb[0]=-1;
        
        st.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(st.size() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.size())
                lb[i]= st.top();
            else 
                lb[i] =-1;
            
            st.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
            // cout<<rb[i]<<" "<<lb[i]<<endl;
            
            ans = max(ans, (rb[i]-lb[i]-1)* heights[i]);
        
        return ans;
    }
};