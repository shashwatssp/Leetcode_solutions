class Solution {
public:
    int mySqrt(int x) {
       
        long long st=1;
        long long en=x;
        long long ans = 0;
        long long mid = (st) + (en-st)/2; 
        while(st<=en)
        {

            if(mid*mid == x)
             return mid;
            else if (mid*mid<x)
            {
               ans = mid;
               st = mid+1;
            }
            else
                en = mid-1;
            
           mid = (st) + (en-st)/2;  
        }
       return ans;
    }
};