class Solution {
public:
    int limit;
    bool check(int mid, vector<int>& weights)
    {
        int n= weights.size();
        int sum=0;
        int lim=0;
        for(int i=0;i<n;i++)
        {   
            sum+= weights[i];
            
            if(sum>mid)
            {
                sum = weights[i];
                if(sum>mid) return false;
                lim++;
            }
        }
        
        if(lim>limit) return false;
        return true;
        
     
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int sum=0;
       for(auto it: weights) sum+=it;
        
        limit=days-1;
        
        int lo=0;
        int hi=sum;
        
       
        
        while(lo<=hi)
        {
            int mid = (lo+hi+1)/2;
            
            if(check(mid,weights))
                hi=mid-1;
            else
                lo=mid+1;
            
        }
        return hi+1;
    }
};