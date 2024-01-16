class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto it: nums) x^=it;
        
        int decider=-1;
        
        for(int i=0;i<32;i++)
        {
            if((x>>i)&1)
            {
                decider = i;
                break;
            }   
        }
        
        if(decider==-1)
            return {};
        
        int a = 0;
        int b = 0;
        
        for(auto it : nums)
        {
            int num = it;
            
            if((num>>decider)&1)
             a^=num;
            else
             b^=num;
        }
        
        return {a,b};
    }
};