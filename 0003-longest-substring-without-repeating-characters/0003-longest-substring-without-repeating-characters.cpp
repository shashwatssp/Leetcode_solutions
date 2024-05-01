class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int cur=0;
       int ans=0;
        
       int n = s.size();
        
        int j=0;
        
        map<char,int>map;
        
        for(int i=0;i<n;i++)
        {
            if(map[s[i]]==0)
            {
                map[s[i]]++;
                cur++;
            }
            else
            {
                while(map[s[i]]!=0)
                {
                    map[s[j]]--;
                    j++;
                }
                
                map[s[i]]++;
                cur = i-j+1;
            }
            
            ans = max(cur,ans);
        }
        
        return ans;
        
        
    }
};