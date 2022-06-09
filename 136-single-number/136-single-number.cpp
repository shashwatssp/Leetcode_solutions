class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>umap;
        
        for(int i=0;i<nums.size();i++)
        {
         umap[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
        int key = nums[i];
            auto it = umap.find(key);
            
            if(it->second==1)
                return it->first;
        }
    return 1;
    }
};