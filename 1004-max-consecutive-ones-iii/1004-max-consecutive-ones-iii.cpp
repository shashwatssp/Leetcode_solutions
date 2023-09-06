class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        int cnt=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==0) cnt++;
    
            if(cnt>k)
            {
                while(cnt>k)
                {
                    if(nums[i]==0) cnt--;
                    i++;
                }
            }
            
                if(cnt<=k)
                ans= max(ans, j-i+1);      
        }
        
        return ans;
    }
};