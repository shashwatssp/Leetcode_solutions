class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int f = nums.size();
        
        int c=0;
        
        for(int i=0;i<f;i++)
        {
            if(i>c)
                return false;
            
            c= max(c, i+nums[i]);
            
        }
return true;
        

        
    }
};