class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        n*=2;
        stack<int>st;
        
        vector<int> nge(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && st.top()<=nums[i])
            {
                st.pop();
            }
            
            if(st.size())
            nge[i] = st.top();
            
            st.push(nums[i]); 
        }
        
        vector<int>ans;
        
        for(int i=0;i<(n/2);i++)
            ans.push_back(nge[i]);
        
        return ans;
    }
};