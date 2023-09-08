class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>v;
        int n = startTime.size();
        
        for(int i=0;i<n;i++)
            v.push_back({endTime[i],{startTime[i],profit[i]}});
        
        sort(v.begin(),v.end());
        
        vector<int>p;
        
        for(auto it:v)
            p.push_back(it.first);
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            int pick = v[i].second.second;

            int find_index = upper_bound(p.begin(), p.end(), v[i].second.first) - p.begin();
            find_index--;
            
            cout<<pick<<" ";
            if(find_index>=0) pick+= dp[find_index];
            
            int non_pick = 0;
            if(i>0) non_pick = dp[i-1];
            
            dp[i] = max(pick,non_pick);
            cout<<dp[i]<<" ";
            cout<<find_index<<endl;
            }
        cout<<endl;
        
        return dp[n-1];
        
    }
};