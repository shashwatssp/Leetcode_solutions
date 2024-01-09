class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        int prev[n];
        int next[n];
        
        for(int i=0;i<n;i++)
            prev[i]=1,next[i]=1;
        
        for(int i=1;i<n;i++)
            if(arr[i]>arr[i-1])
                prev[i]+=prev[i-1];
      
        
        for(int i=n-2;i>=0;i--)
            if(arr[i]>arr[i+1])
                next[i]+=next[i+1];

        int ans=0;
        
        for(int i=1;i<n-1;i++)
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
             ans = max(ans, prev[i]+next[i]-1);
        
    
        return ans;
    }
};