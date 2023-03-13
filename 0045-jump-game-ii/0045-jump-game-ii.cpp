class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()==1) return 0;
        
        int pos = nums[0];
        int jumps=1;
        if(pos==0) return -1;
        
        priority_queue<int>pq;
        for(int i=1;i<nums.size();i++)
        {     
            if(pos<i)
            {
                pos = pq.top();
                jumps++;
                while(!pq.empty())
                    pq.pop();
            }
            
            pq.push({nums[i]+i});
        }
        
        
        if(pos>=nums.size()-1)
            return jumps;
        return -1;
        
    }
};