class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = -1;
        int cnt=0;
        
        for(auto it: nums)
        {   
            if(cnt==0)
                cur = it;
            
            if(it==cur)cnt++;
            else cnt--;
        }
        
        
        return cur;
    }
};