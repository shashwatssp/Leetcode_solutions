class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      long long ans=0;
      map<long long,long long>map[n+1];
      
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<i;j++)
           {
               long long dif = (long long)nums[i] - (long long)nums[j];
               ans += map[j][dif];
               map[i][dif]+=map[j][dif]+1;
           }
       }
        return ans;
    }
};