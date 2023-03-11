class Solution {
public:
    int longestSubstring(string s, int k) {
        map<char,int>map;
        for(auto it : s) map[it]++;
        
        int ans=0;
        bool isValid=true;
        int i=0;
        for(int j=0;j<s.size();j++)
        {
            if(map[s[j]]<k)
            {   
               while(j<s.size() && map[s[j]]<k) j++;
                j--;
                
                isValid=false;
                string a = s.substr(i,j);
                
                ans = max(ans,(longestSubstring(a,k)));   
                i=j+1;
            }
        }
        
        string b = s.substr(i);
        return isValid?s.size():max(ans,longestSubstring(b,k));
    }
};