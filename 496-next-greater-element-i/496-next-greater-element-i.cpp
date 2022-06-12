class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
stack<int> st;
        vector<int> right(nums2.size(),-1);
        
        for(int i = nums2.size()-1; i>=0;i--)
        {
            while(!st.empty() and st.top()<nums2[i])
                st.pop();
            if(!st.empty()) right[i]= st.top();
            
            st.push(nums2[i]);

        }
        
        vector<int>ans(nums1.size());
        map<int,int>index;
        
        for(int i=0;i<nums2.size();i++) index[nums2[i]] = i;
        for(int i=0;i<nums1.size();i++) ans[i] = right[index[nums1[i]]];
                                                       
         return ans;                                              
        
        
    }
    
};