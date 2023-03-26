class Solution {
public:
    int dp[101][101][28][11];
    // idx,k,p,f
    int solve(int idx, int k, int p, int f, string &s)
    {
        int ans = INT_MAX;
        
        if(k<0) return ans;
        if(idx==s.size()) return 0;
        if(f>10)f=10;
        
        if(dp[idx][k][p][f]!=-1) return dp[idx][k][p][f];
        
        ans = min(ans, solve(idx+1,k-1,p,f,s));
        
        if(s[idx]-'a'== p)
        {
            if(f==1 || f==9)
            ans = min(ans, 1 + solve(idx+1,k,p,f+1,s));
            else ans = min(ans, solve(idx+1,k,p,f+1,s));
        }
        else ans = min(ans, 1 + solve(idx+1,k,s[idx]-'a',1,s));
        return dp[idx][k][p][f] = ans; 
    }
    int getLengthOfOptimalCompression(string s, int k) {
      memset(dp,-1,sizeof(dp));
      if(k>=s.size()) return 0;
      string c = s;
      sort(c.begin(),c.end());
      if(c[0]==c[c.size()-1])
      {   
          int z = c.size()-k;
          if(z<=0) return 0;
          if(z==1) return 1;
          if(z<10) return 2;
          if(z<100) return 3;
          if(z<1000) return 4;    
      }
       
        return solve(0,k,27,0,s);
    }
};