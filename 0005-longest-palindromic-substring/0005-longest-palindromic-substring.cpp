class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n+1][n+1];
        string ans = "";
        for(int len=0;len<n;len++)
        {
            for(int i=0,j=len; j<n; i++,j++)
            {
                if(len==0) dp[i][j] = true;
                else if(len==1) dp[i][j] = (s[i]==s[j])?true:false;
                else dp[i][j] = (s[i]==s[j] && dp[i+1][j-1])?true:false;
                
                if(dp[i][j]) ans = s.substr(i,j-i+1);
            }
        }
        return ans;
    }
};