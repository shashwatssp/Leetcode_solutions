class Solution {
public:
    string ans="";
    void solve(string temp, int n, int &k)
    {
        if(temp.size()==n)
        {
            k--;
            if(k==0)
            ans = temp;
            
            return;
        }
        

        for(char ch = 'a';ch<='c';ch++)
        {
            if(temp=="" || temp.back()!=ch)
            {
                solve(temp+ch,n,k);
            }
        }
    }
    string getHappyString(int n, int k) {
        solve("",n,k);
        return ans;
    }
};