class Solution {
public:

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        
        long long int mod = 1e9+9;
        
        long long int hash[n];
        
        
        long long int p = 31;
        
        long long int num = 31;
        
        long long int pw[n];
        
        for(int i=0;i<n-1;i++)
        {
            hash[i]= num;
            
            if(nums[i+1]>nums[i])
            {
                hash[i] = (hash[i]*3)%mod;
            }
            else if(nums[i+1]==nums[i])
            {
                hash[i] = (hash[i]*2)%mod;
            }
            else
            {
                hash[i] = (hash[i]*1)%mod;
            }
            
            if(i>0)
                hash[i] = (hash[i]+hash[i-1])%mod;
            
            pw[i]=num;
            num = (num*p)%mod;
            
        }
        
        
        
        int m = pattern.size();
        
        long long int pat[m];
        
        
        p = 31;
        
        num = 31;
        
        for(int i=0;i<m;i++)
        {
            pat[i]= num;
            
            if(pattern[i]==1)
            {
                pat[i] = (pat[i]*3)%mod;
            }
            else if(pattern[i]==0)
            {
                pat[i] = (pat[i]*2)%mod;
            }
            else
            {
               pat[i] = (pat[i]*1)%mod;
            }
            
            if(i>0)
                pat[i] = (pat[i]+pat[i-1])%mod;
            
            
            num = (num*p)%mod;
        }
        
    
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(i+m>n) break;
            
            long long int val = hash[i+m-1];
            
            if(i>0) val-= hash[i-1];
            
            val = (val+mod)%mod;
            
            long long int fix = pat[m-1];
            
            if(i>0)
            fix = (fix*pw[i-1]%mod);
            
            
            
            if(val==fix) ans++;
        }
        
        return ans;
    }
};