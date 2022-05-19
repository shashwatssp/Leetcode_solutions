class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]==0) nums[i]=-1;
        int ans=0;
        unordered_map<int,int>  map;
        int cur=0;
        for(int i=0;i<n;i++) {
            cur+=nums[i];
            if(cur==0) ans=i+1;
            if(map.count(cur)){
                ans=max(ans,i-map[cur]);
            } 
           else map[cur]=i;
        }
        return ans;
        
        
    }
};