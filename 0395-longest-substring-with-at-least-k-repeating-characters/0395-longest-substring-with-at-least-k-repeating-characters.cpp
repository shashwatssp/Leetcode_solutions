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
                i=j+1;
                ans = max(ans,longestSubstring(a,k));
            }
        }
        
        if(isValid) return s.size();
        else return max(ans,longestSubstring(s.substr(i),k));
        
    }
};