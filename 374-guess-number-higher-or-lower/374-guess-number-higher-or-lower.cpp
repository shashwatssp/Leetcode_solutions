/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo=1;
        
        int hi=n;
        
        while(lo<=hi)
        {
            int m = lo + (hi-lo)/2;

            if(guess(m)==0)
                return m;
            else if(guess(m)==-1)
                hi = m - 1;
            else
                lo = m +1;
        }
        
        return -1;
    }
        
};