class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int j=0;
        
        priority_queue<pair<int,int>>mx,mn;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            mx.push({nums[i],i});
            mn.push({-nums[i],i});
            
            while(mx.size() && mx.top().second<j)mx.pop();
            while(mn.size() && mn.top().second<j)mn.pop();
            
            if(mx.top().first+ mn.top().first > limit) j++;
            
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};