class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        
        long long int mod = 1e9+7;
        
        long long int pre_smoll[n];
        long long int next_smoll[n];
        
        for(int i=0;i<n;i++)
        {
            pre_smoll[i] = i+1;
            next_smoll[i] = n-i;
        }
        
        
        for(int i=0;i<n;i++)
        {
            while(st.size() && arr[st.top()]>=arr[i])
            {
                next_smoll[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && arr[i]<arr[st.top()])
            {
                pre_smoll[st.top()] = st.top()-i;
                st.pop();
            }
            st.push(i);
        }
        
        long long int ans=0;
        
        for(int i=0;i<n;i++)
           ans = (ans + arr[i]*(pre_smoll[i]*next_smoll[i]))%mod;
        
        
        return ans;
    }
};