class Solution {
public:
    int mod = 1e9+7;
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<int> v = arr;
        
        int n = v.size();
        
        for(auto it: arr)
        v.push_back(it);
        
                for(auto it: arr)
        v.push_back(it);
       
        long long int cs=0;
        long long int msf=0;
        
        long long int msf1=0;
        long long int msf2=0;
        long long int msf3=0;
        
        int i=0;
        
        for(auto it : v)
        {
            if((cs+it)%mod>=0)
                (cs = cs+it)%mod;
            else
                cs = 0;
            
            msf = max(msf,cs);
            i++;
            
            msf%=mod;
            
            if(i==n) msf1 = msf;
            if(i==2*n) msf2 = msf;
            if(i==3*n) msf3 = msf;
        }
        
        if(k==1) return msf1;
        
        
        
        long long int x = msf2-msf1;
        long long k1=k;
        
        if(msf3>msf2)
        msf1 = (msf1+(k1-1)*x)%mod;
        else
        msf1 = msf2;    
        
        return msf1;
    }
};