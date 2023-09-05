class Solution {
public:
    int helper(vector<int>& nums, int k)
    {
    int n = nums.size();
    map<int,int>map;
        
    int i=0;
    int cnt=0;
        
    for(int j=0;j<n;j++)
    {
       map[nums[j]]++;
       
        if(map.size()<=k)
        {   
            cnt+=(j-i+1);
        }
        else
        {
            while(i<j && map.size()>k)
            {
                map[nums[i]]--;
                if(map[nums[i]]==0)
                    map.erase(nums[i]);
                i++;
            }
            cnt+=j-i+1;
        }
    }
        
        return cnt;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    
    if(k>1)
    return helper(nums,k)- helper(nums,k-1);
        
    return helper(nums,k);    

    }
};