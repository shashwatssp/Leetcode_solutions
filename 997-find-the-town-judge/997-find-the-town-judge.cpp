class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>score(n+1,0);
        vector<bool>visited(n+1,false);
        
        for(auto x : trust)
        {
            visited[x[0]]=true;
            score[x[1]]++;
        }
        
        for(int i=1;i<=n;i++)
            if(score[i]==n-1  && visited[i]==false)
                return i;
        
        return -1;
        
    }
};