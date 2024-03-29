class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int l=0;
        int r=1;
        int ans=0;
        sort(intervals.begin(),intervals.end());
        while(r<n)
        {
        if(intervals[l][1]<= intervals[r][0]) l=r,r++;
            else if (intervals[l][1]<=intervals[r][1]) r++,ans++;
            else l=r,r++,ans++;

        }
        return ans;
    }
};