class Solution {
public:
    int mod=1e9+7;
    int countHousePlacements(int n) {
       long long int x=1;
       long long int y=1;
        for(int i=2;i<=n+1;i++)
        {   
            long long z=y;
            y+=x;
            y%=mod;
            x=z;

        }
        y *= y;
        y%=mod;
        return y;
    }
};