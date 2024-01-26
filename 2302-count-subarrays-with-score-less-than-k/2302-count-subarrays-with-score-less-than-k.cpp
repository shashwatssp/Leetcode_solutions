class Solution {
public:
    vector<long long>pre;
    int find(int ind, long long k)
    {
        int lo=0;
        int hi=ind;
        
        while(lo<=hi)
        {   
            int mid = (lo+hi+1)/2;
            
            long long sum = pre[ind];
            if(mid>0) sum-= pre[mid-1];
            sum*= (ind-mid+1);
            
            // cout<<ind<<" "<<mid<<" "<<sum<<endl;
            
            if(sum<k)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid + 1;
            } 
        }
        
        return (ind-(hi+1)+1);
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            pre.push_back(nums[i]);
            if(i>0)
            pre[i]+=pre[i-1];    
        }
        
        
        long long ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans+= find(i,k);
        }
        
        return ans;
        
    }
};