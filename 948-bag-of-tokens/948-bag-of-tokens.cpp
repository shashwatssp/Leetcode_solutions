class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans=0;
        int points=0;
        
        int left=0;
        int right= tokens.size()-1;
        
        sort(tokens.begin(),tokens.end());
        
        while(left<=right)
        {
        if(power>=tokens[left])
        {
            power-=tokens[left++];
            ans = max(ans,++points);
        }
            else if(points>0)
            {
                points-=1;
                power+=tokens[right--];
            }
            else
                break;
        }
        
        return ans;
    }
};