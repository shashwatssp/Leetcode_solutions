class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=INT_MAX;
        deque<pair<long long,long long>>dq;
        long long sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(sum>=k)
            {
                if(ans>i+1) ans = i+1;
            }
            
            //maximizing answer
            
            while(!dq.empty() && sum - dq.front().first >= k)
            {   
                if(ans>i- dq.front().second)
                ans = i- dq.front().second;
  
                dq.pop_front();
            }
            
            while(!dq.empty() && sum <= dq.back().first)
            {
                dq.pop_back();
            }
            
            
            dq.push_back({sum,i});
        }
        
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};