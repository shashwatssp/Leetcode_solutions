class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>std,helper;
        
        for(int i=1;i<=k;i++) std.insert(i);
        
        int n = rolls.size();
        
        int ans=1;
        
        for(int i=n-1;i>=0;i--)
        {
            helper.insert(rolls[i]);
            
            if(helper==std)
            {
                ans++;
                helper.clear();
            }
        }
        
        return ans;
    }
};