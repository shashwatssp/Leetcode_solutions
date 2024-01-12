class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int>ans,left,right;
        
        for(int i=0;i<n;i++)
        {
            char ch = expression[i];
            
            if(ch=='+' || ch=='-' || ch=='*')
            {
                left = diffWaysToCompute(expression.substr(0,i));
                right = diffWaysToCompute(expression.substr(i+1));
                
                for(int l : left)
                {
                    for(int r: right)
                    {
                        if(ch=='+')
                            ans.push_back(l+r);
                        if(ch=='-')
                            ans.push_back(l-r);
                        if(ch=='*')
                            ans.push_back(l*r);
                    }
                }
            }

        }
        
                    if(ans.size()==0)
                return{stoi(expression)};
            
                return ans;
    }
};