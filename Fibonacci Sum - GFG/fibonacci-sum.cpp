//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int MOD = 1e9+7;
    long long int fib[100100];
    long long int fibo(long long int N)
    {
    if(fib[N]!=-1) return fib[N]%MOD;
    return fib[N]= fibo(N-1)%MOD +fibo(N-2)%MOD;
    }
    long long int fibSum(long long int N){
        
        memset(fib,-1,sizeof(fib));
        fib[0]=0;
        fib[1]=1;
        fib[2]=1;
        fibo(N);
        long long int sum=0;
        for(int i=0;i<=N;i++)
        {
          sum+= fib[i]%MOD;
          sum%=MOD;
        }
        
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends