class Solution {
public:
    set<vector<int>>set;
    void solve(int i, map<int,int>&map, int n, vector<int>temp)
    {
        if(i==n)
        {
            set.insert(temp);
            return;
        }
        
        for(auto it: map)
        {
            if(it.second==0) continue;
            
            map[it.first]--;
            
            temp[i] = it.first;
            
            solve(i+1,map,n,temp);
            
            temp[i]=0;
            
            map[it.first]++;
        }
         
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int>map;
        int n = nums.size();
        
        for(auto it: nums) map[it]++;
        vector<int>temp(n,0);
        solve(0,map,n,temp);
        vector<vector<int>>ans;
        for(auto it: set) ans.push_back(it);
        return ans;
    }
};