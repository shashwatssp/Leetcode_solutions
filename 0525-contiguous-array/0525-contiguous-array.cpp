class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int pre[n];
        
        int ans=0;
        
        map<int,int>map;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i])pre[i]=1;
            else pre[i]=-1;
            
            if(i>0) pre[i]+=pre[i-1];
            
            if(pre[i]==0) ans=i+1;
            
            if(map[pre[i]])
                ans = max(ans,i-map[pre[i]]+1);
            else
                map[pre[i]]=i+1;
        }

        return ans;

    }
};