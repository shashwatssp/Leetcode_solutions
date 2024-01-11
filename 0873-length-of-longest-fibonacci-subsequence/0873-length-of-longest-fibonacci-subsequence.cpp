class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        map<int,int>map;
        
        for(int i=0;i<n;i++) map[arr[i]] = i+1;
        
        int dp[n+1][n+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                dp[i][j] = 2;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = arr[i]+arr[j];
                
                if(map.find(sum)!=map.end())
                {
                    int idx = map[sum]-1;
                    
                    dp[j][idx] = dp[i][j]+1;
                    ans = max(ans, dp[j][idx]);
                }
            }
        }
        
        if(ans<3) ans=0;
        return ans;
    }
};