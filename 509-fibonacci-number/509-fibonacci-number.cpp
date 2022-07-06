class Solution {
public:
 
    
    vector<int>a = vector<int>(31,-1);
    
    int fib(int n) {
        
        if(n==1 || n==0)
            return n;
          
            if(a[n]!=-1)
                return a[n];
        
            return a[n]=fib(n-1)+fib(n-2);
        
    }
};