class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long pre[beans.size()];
        
        long long total=0;
        for(auto it : beans)total+=it;
        long long cur=0;
        long long ans = 1e18;
        
        for(int i=0;i<beans.size();i++)
        {
          total-=beans[i];  
          long long alt = cur+(total - (beans.size()-1-i)*beans[i]);
          ans = min(ans,alt);  
          cur+=beans[i];    
        }
        return ans;
    }
};