class Solution {
public:
    int strStr(string h, string n) {
        int i=0;
        if(n.size()>h.size())
            return -1;
        
        for(i=0;i<=h.size()-n.size();i++)
        {
         int count=0;
            for(int j=0;j<n.size();j++)
            {
            if(h[i+j]==n[j])
                count++;
            }
            
            if(count==n.size())
                return i;
        }
        return -1;
        
    }
};