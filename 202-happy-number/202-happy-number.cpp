class Solution {
public:
    
    int sumsquare(int n)
    {
        int ans=0;
        
        while(n)
        {
            int d = n%10;
            n/=10;
            
            ans+=(d*d);
        }
        
        return ans;

    }
    
    bool isHappy(int n) {
        
        set<int> check;
        while(n)
        {
            if(check.find(n)!=check.end())
            return false;
            
            check.insert(n);
            
            if(n==1)
            return true;
            
            n = sumsquare(n);         
            
        }
        return false;
    }
};