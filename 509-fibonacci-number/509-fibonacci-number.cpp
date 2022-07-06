class Solution {
public:
 
    
    vector<int>a = vector<int>(31,-1);
    
    int fib(int n) {
    a[0]=0;
    a[1]=1;
        
        for(int i=2;i<=n;i++)
            a[i]=a[i-1]+a[i-2];
        
        return a[n];
        
    }
};