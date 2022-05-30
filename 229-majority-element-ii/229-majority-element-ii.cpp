class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
  vector<int> ans;
        int c1=INT_MIN;
        int c2=INT_MIN;
        int v1=0;
        int v2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==c1)
                v1++;
            else if(nums[i]==c2)
                v2++;
            else if(v1==0)
                c1=nums[i], v1=1;
            else if(v2==0)
                c2=nums[i], v2=1;
            else
            {
                v1--;
                v2--;
            }
        }
        
       v1=0;
       v2=0;
        
       for(int i=0;i<nums.size();i++)
       {
       if(nums[i]==c1)
           v1++;
       if(nums[i]==c2)
           v2++;
       }
        
        if(v1>nums.size()/3)
            ans.push_back(c1);
        if(v2>nums.size()/3)
            ans.push_back(c2);
        
    
        return ans;
    }
};