class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
    map<int,int>map;
    int sum;
    int mx=0;    
    for(auto it: wall)
    {   
        sum=0;
        for(auto zz: it)
        {
            sum+=zz;
            map[sum]++;
        }
    }
        
        for(auto it: map)
            if(it.first!=sum)
            mx = max(mx, it.second);
        
        return wall.size()-mx;
    }
};