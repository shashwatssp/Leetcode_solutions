class Solution {
public:
    int dp[505][505];
    int solve(int left, int right, vector<int>& piles,int turn)
    {
       if(left>right) return 0;
        if(dp[left][right]) return dp[left][right];
        
            int ansl = piles[left] + solve(left+1,right,piles,1-turn);
            int ansr = piles[right] + solve(left,right-1,piles,1-turn);
        
        if(turn==0)
            return dp[left][right] =  max(ansl,ansr);
        else
           return dp[left][right] = min(ansl,ansr); 
  
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,piles,0);
    }
};