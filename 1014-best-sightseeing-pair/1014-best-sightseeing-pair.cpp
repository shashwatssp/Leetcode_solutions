class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mx=INT_MIN;
        int ans= INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans, mx+ values[i]-i); 
            mx = max(mx, values[i]+i);
        }
        
        return ans;
    }
};