class Solution {
public:
    int dp[201][201];
    int solve(int i, int j,vector<vector<int>>& triangle )
    {
        if(i==triangle.size())
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left = (dp[i+1][j]!=-1)?dp[i+1][j]:solve(i+1,j,triangle);
        int right = (dp[i+1][j+1]!=-1)? dp[i+1][j+1]:solve(i+1,j+1,triangle);
        
       return dp[i][j] = min(left,right) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};