class Solution {
public:
    int n;
    vector<vector<int>>ans;
    set<vector<int>>set;
    void solve(int i,vector<int>& nums, vector<int>temp)
    {   
       
        if(i==n)
        {   
            if(set.find(temp)==set.end())
            {
                ans.push_back(temp);
                set.insert(temp);
            } 
        }
            
        
        for(int j=0;j<n;j++)
        {
            if(temp[j]==-11)
            {
                temp[j] = nums[i];
                solve(i+1,nums,temp);
                temp[j]=-11;
            }
        }
    
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
       
    
        vector<int>temp(n,-11);
         solve(0,nums,temp);
        return ans;
    }
};