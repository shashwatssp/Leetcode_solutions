class Solution {
public:
    vector<long long>odd,even,oddtarget,eventarget;
    
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        for(auto it: nums)
        {
            if(it&1)
                odd.push_back(it);
            else
                even.push_back(it);
        }
        
        for(auto it: target)
        {
            if(it&1)
                oddtarget.push_back(it);
            else
                eventarget.push_back(it);
        }
        
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        sort(oddtarget.begin(),oddtarget.end());
        sort(eventarget.begin(),eventarget.end());
        
        
        int oddsz = odd.size();
        int evensz = even.size();
        
        long long ans=0;
        
        for(int i=0;i<oddsz;i++)
        {
            ans+= abs(odd[i]-oddtarget[i])/2;
        }
        
         for(int i=0;i<evensz;i++)
        {
            ans+= abs(even[i]-eventarget[i])/2;
        }       
        
        return ans/2;
        
        
    }
};