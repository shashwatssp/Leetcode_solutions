class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, cur = 2;
        if(n==1)
            return prev;
        if(n==2)
            return cur;
        for(int i = 2; i < n; i++){
            int next = cur;
            cur += prev;
            prev = next;
        }
        return cur;
    }
};