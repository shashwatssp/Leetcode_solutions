class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      priority_queue<pair<int,int>>pq;
        pq.push(make_pair(nums[0],0));
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
        while(!pq.empty() && pq.top().second<i-k) pq.pop();
            ans = pq.top().first+nums[i];
            //pq.pop();
            pq.push(make_pair(ans,i)); 
        }
        return ans;
    }
};