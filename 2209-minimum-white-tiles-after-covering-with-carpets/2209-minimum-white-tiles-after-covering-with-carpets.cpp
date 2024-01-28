class Solution {
public:
    int dp[1005][1005];
    int suff[1005];
    int solve(int i,string &floor,int num,int len,int n)
    {   
        if(i>=n) return 0;
        
        if(dp[i][num]!=-1) return dp[i][num];
        
        if(num==0)
            return suff[i];
        
        
        int ans = solve(i+1,floor,num,len,n);
        
        if(floor[i]=='1') ans++;
        
        if(floor[i]=='1')
        ans = min(ans, solve(i+len,floor,num-1,len,n));
        
        return dp[i][num] = ans;
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp,-1,sizeof(dp));
        for(int i=floor.size()-1;i>=0;i--)
        {
            if(floor[i]=='1')
            suff[i]=1;
            
            if(i!=floor.size()-1)
            suff[i]+=suff[i+1];    
        }
        return solve(0,floor,numCarpets,carpetLen,floor.size());
    }
};