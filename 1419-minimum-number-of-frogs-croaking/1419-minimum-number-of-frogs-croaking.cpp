class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
    int n = croakOfFrogs.size();
    int c=0,r=0,o=0,a=0,k=0;
    
    int ans=0;
        
    for(auto it: croakOfFrogs)
    {
        if(it=='c')
        {
            c++;
            ans = max(ans,c);
        }
        else if(it=='r')
            r++;
        else if(it=='o')
            o++;
        else if(it=='a')
            a++;
        else if(it=='k')
           c--,r--,o--,a--;
        
        if(c<r || r<o || o<a ) return -1;
    }
        
    if(c==0 && r==0 && o==0 && a==0) return ans;
    else return -1;    
    }
};