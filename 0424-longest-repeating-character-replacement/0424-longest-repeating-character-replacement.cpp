class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int j=0;
        
        vector<int>freq(26,0);
        int cur=0;
        
        int ans=0;
       
        
        for(int i=0;i<n;i++)
        {   
            freq[s[i]-'A']++;
            
            cur = max(cur,freq[s[i]-'A']);
            
            if(i-j+1-cur>k)
            freq[s[j++]-'A']--;
            
            ans = max(ans, i-j+1);
            
        }
        
        return ans;
    }
};