class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>>modifive;
        int n = nums.size();
        for(int i=0;i<n;i++)
            modifive.push_back({nums[i],i});
        
        sort(modifive.begin(),modifive.end());
        
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {   
            if(i>0 && modifive[i].first==modifive[i-1].first)
            ans[modifive[i].second] = ans[modifive[i-1].second];  
            else
            ans[modifive[i].second]=i;
        }
        
        return ans;
    }
};