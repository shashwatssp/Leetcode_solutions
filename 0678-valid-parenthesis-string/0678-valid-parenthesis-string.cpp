class Solution {
public:
    bool checkValidString(string s) {
        stack<int>bracket,star;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            bracket.push(i);
            else if(s[i]==')')
            {
                if(bracket.size())
                    bracket.pop();
                else if(star.size())
                    star.pop();
                else
                    return false;
            }
            else
            {
                star.push(i);
            }
        }
        
        if(bracket.size())
        {   
            if(star.size()==0) return false;
            int x = star.top();
            int y= bracket.top();
            while(x>y)
            {
                star.pop();
                bracket.pop();
             if(star.size() && bracket.size())
             {
             x = star.top();
             y= bracket.top(); 
             }
                else
                    break;


            }
        }
        
        if(bracket.size()) return false;
        return true;
    }
};