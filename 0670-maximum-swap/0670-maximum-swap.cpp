class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>mx_idx(n,-1),mx_val(n,-1);
        
        int maxi=-1;
        int idx=-1;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]-'0'>maxi)
            {
                maxi = s[i]-'0';
                idx = i;
            }
            
            mx_val[i] = maxi;
            mx_idx[i] = idx;
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0'!= mx_val[i] && mx_idx[i]!=i)
            {
                swap(s[i],s[mx_idx[i]]);
                break;
            }
        }
        
        return stoi(s);
        
    }
};