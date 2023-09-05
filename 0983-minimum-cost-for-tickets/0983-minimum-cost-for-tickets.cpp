class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
       vector<int>dp(n+1,0);
       
       
       for(int i=n-1;i>=0;i--)
       {
           int c1 = costs[0] + dp[lower_bound(days.begin(),days.end(),days[i]+1)-days.begin()];
           int c2 = costs[1] + dp[lower_bound(days.begin(),days.end(),days[i]+7)-days.begin()];
           int c3 = costs[2] + dp[lower_bound(days.begin(),days.end(),days[i]+30)-days.begin()];
           
           dp[i] = min(c1, min(c2,c3));
       }
        return dp[0];
    }
};