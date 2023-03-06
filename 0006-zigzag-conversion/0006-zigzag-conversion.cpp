class Solution {
public:
    string convert(string s, int numRows) {
      int step= 2*numRows-2;
      string ans="";
        
      if(numRows==1) return s;  
      
        for(int i=0;i<numRows;i++)
        {
            for(int j=i;j<s.size();j+=step)
                
            {   ans.push_back(s[j]);
                int target = j + step - 2*i;
                if(i!=0 && i!= numRows-1 && target<s.size())
                {
                    ans.push_back(s[target]);
                }
            }
        }
        return ans;
    }
};