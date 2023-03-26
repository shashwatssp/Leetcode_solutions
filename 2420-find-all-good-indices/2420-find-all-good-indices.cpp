class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int init[nums.size()+1],dend[nums.size()+1];
        init[0]=1;
        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i]<=nums[i-1])
            init[i]= init[i-1] + 1;
            else init [i] = 1;
        }
        
        dend[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--) 
        {
            if(nums[i]<=nums[i+1])
            dend[i]= dend[i+1] + 1;
            else dend[i]=1;
        }
        
        vector<int>ans;
        for(int i=1;i<nums.size()-1;i++)
        {
        //cout<<init[i-1]<<" "<<dend[i+1]<<endl;
            if(init[i-1]>=k && dend[i+1]>=k)
                ans.push_back(i);
        }
        return ans;
    }
};