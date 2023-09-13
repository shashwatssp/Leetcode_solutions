class Solution {
public:
    bool search(int mid,vector<int>& bloomDay, int k, int m)
    {
        int ans=0;
        int count=0;
        
        for(auto it: bloomDay)
        {
            if(it<=mid)
                count++;
            else
            {   
                ans+= count/k;
                count=0;
            }

        }
        ans+= count/k;
        
    
        if(ans>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(auto it: bloomDay)
        {
            mn = min(mn, it);
            mx = max(mx, it);
        }
        
        int ans=-1;
        

        while(mn<=mx)
        {
            int mid = (mn+mx+1)/2;
           
            bool find = search(mid,bloomDay,k,m);
            
            if(find)
            {
               ans=mid; 
               mx = mid-1; 
            }
            else
            {
                mn = mid+1;
            }
 
        }
        
        return ans;
    }
};