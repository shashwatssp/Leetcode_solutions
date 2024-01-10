class Solution {
public:
    int count=0;
    void solve(int i, string s)
    {
        count++;
        
        for(int j=i;j<s.size();j++)
        {
            if(i==j)
                solve(i+1,s);
            else
            {
                if(s[i]!=s[j])
                {
                    swap(s[i],s[j]);
                    solve(i+1,s);
                }
            }
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        solve(0,tiles);
        return count-1;
    }
};