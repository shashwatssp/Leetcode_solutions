class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(k<nums[0])
        {
            long long x = k;
            return x*(x+1)/2;
        }
        
        long long sum=0;
        
        if(nums[0]>1)
        {
            long long x = nums[0]-1;
            sum+= x*(x+1)/2;
            k-=x;
        }
        
        int i=0,j=1;
        
        while(j<n && k>0)
        {
            
            while(j<n && nums[i]+1>=nums[j])
            i++,j++;
            
            if(j>=n) break;
            
            long long diff = nums[j]-nums[i]-1;
            
            long long t = diff;
            
            if(k<t) t = k; 
            
            long long x = nums[i]+t;
            long long y = nums[i];
            
            sum+= x*(x+1)/2;
            sum-= y*(y+1)/2;
            
            k-=t;
            i++;
            j++;

        }
        
        if(k>0)
        {
            long long t = k;
            
            long long x = nums[i]+t;
            long long y = nums[i];
            sum+= x*(x+1)/2;
            sum-= y*(y+1)/2;
        }
        
        return sum;
    }
};