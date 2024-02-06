class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int n = nums1.size();
        map<long long,int>map;
        
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            map[(abs(nums1[i]-nums2[i]))]++;
            mx = max(mx, (abs(nums1[i]-nums2[i])));
        }
        
        vector<int>v(mx+1,0);
        
        for(auto it: map)
            v[it.first] = it.second;
        
        long long op = k1+k2;
        
        
        long long ans=0;
        
        
        for(long long i=mx;i>0;i--)
        {
            long long x = i;;
            int freq = v[i];
            
               if(op>=freq)
            {
                op-=freq;
                v[i-1]+=freq;   
                continue; 
            }
            else
            {   
                int left = freq-op;
                
                ans+= (x*x*left);
                
                v[i-1]+=op;
                
                op=0;
            }
            
        }
        
        return ans;
    }
};