class Solution {
public:
    
   void comb(string digits, vector<string> &res, string nums[], int i, string s)
      {
       
       
   if(i==digits.size())
   {
    res.push_back(s);
    return;
   }
       string val = nums[digits[i]-'0'];
       
       for(int j=0;j<val.length();j++)
       {
       comb(digits,res,nums,i+1,s+val[j]);
       }
        

    }
    vector<string> letterCombinations(string digits) { 
       int n = digits.size();
        vector<string> res;
        
        if(n==0) return res;
        
        string nums[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        comb(digits,res,nums,0,"");
        return res;
    }
};