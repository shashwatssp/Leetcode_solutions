class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     
    map<string,int> mp;
    
    for(auto it : words)
    mp[it]++;
     
     int ans = 0;
     int flag = 0;
        
    for(auto it : mp)
    {
      string s = "";
      s = it.first;
      reverse(s.begin(),s.end());
    
      if(s==it.first)
      {
          ans+= (it.second/2);
          if(it.second%2) flag=2;
      }
        else
        {
        ans +=min(it.second,mp[s]);
        mp.erase(s);
        }
    }
        ans=ans*4;
        
        ans += flag;
        return ans;

    }
};