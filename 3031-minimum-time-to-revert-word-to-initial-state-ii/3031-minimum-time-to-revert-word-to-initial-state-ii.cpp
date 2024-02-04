class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        
        vector<long long>pow(n+1,1),pref(n+1,0);
        
        long long p = 31;
        long long mod = 1e9+7;
        
        for(int i=1;i<=n;i++)
        {
            pow[i] = (pow[i-1]*p)%mod;
            pref[i] = (pref[i-1] + (pow[i]*(word[i-1]-'a'+1)) + mod)%mod;
        }
        
        int ans=1;
        
        for(int i=k;i<n;i+=k)
        {
            long long after = (pref[n]-pref[i]+mod)%mod;
            
            long long before = (pref[n-i]*pow[i])%mod;
            
            if(after==before) return ans;
            ans++;
        }
        return ans;
    }
};