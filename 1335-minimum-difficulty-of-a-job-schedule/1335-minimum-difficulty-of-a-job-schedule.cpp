class Solution {
public:
    int dp[11][301];
    int solve(int idx,vector<int>& jobDifficulty,int d,int n)
    {
        if(d==1)
        {
            int mx=-1;
            for(int i=idx;i<n;i++)
                mx = max(mx,jobDifficulty[i]);
            
            return mx;
        }
        
        if(dp[d][idx]!=-1) return dp[d][idx];
        
        int ans = INT_MAX;
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        for(int i=idx;i<n-d+1;i++)
        {
          ans1 = max(ans1,jobDifficulty[i]);
            ans2 = solve(i+1,jobDifficulty,d-1,n);
            ans = min(ans,ans1+ans2);
            
            //cout<<i<<" "<<ans1<<" "<<ans2<<endl;
        }
        return dp[d][idx]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n) return -1;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,jobDifficulty,d,n);
    }
};