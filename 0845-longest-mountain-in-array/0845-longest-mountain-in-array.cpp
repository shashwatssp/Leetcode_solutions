class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        int ans=0;
        
        for(int i=1;i<n-1;i++)
        {
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1])
            {
                int prev = i-1;
                int next = i+1;
                
                while(prev-1>=0 && arr[prev-1]<arr[prev])
                    prev--;
                
                while(next+1<n && arr[next+1]<arr[next])
                    next++;
                
                ans = max(ans, next-prev+1);
            }
        }
        
        return ans;
    }
};