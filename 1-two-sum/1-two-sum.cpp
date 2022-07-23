class Solution {
public:
vector<int> twoSum(vector<int> &numbers, int target) {
 map<int,int> mp;
    
    vector<int> ans;
    
    for(int i=0;i<numbers.size();i++)
    {
    if(mp.find(target-numbers[i])==mp.end())
    mp[numbers[i]]=i;
    else
    {
    ans.push_back(mp[target-numbers[i]]);
    ans.push_back(i);
    break;
    }
    }
    
    return ans;
    }
};