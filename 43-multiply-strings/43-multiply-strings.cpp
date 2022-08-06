class Solution {
public:
    string multiply(string num1, string num2) {
    string ans(num1.size() + num2.size(), '0');
    for(int i = num1.size()-1; i>=0; i--)
    {
        int carry = 0;
        for(int j = num2.size()-1; j>=0;j--)
        {
            int temp = (ans[i+j+1]-'0') + ((num1[i]-'0')*(num2[j]-'0')) + carry;
            ans[i+j+1] = temp%10 + '0';
            carry=temp/10;
        }
        ans[i]+=carry;
    }
        
        int pos = 0;
        while(pos<ans.size() && ans[pos]=='0') pos++;
        if(pos==ans.size()) return "0";
        
        return ans.substr(pos);
    }
};