class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur=nums[0];
        int stc=1;
        for(int i=1;i<nums.size();i++)
        {
         if(stc==0)
         {
             cur=nums[i];
         }
         if(nums[i]==cur)
         {
        stc++;
         }
            else
            {
                stc--;
            }
        
    }
        return cur;
    }
};