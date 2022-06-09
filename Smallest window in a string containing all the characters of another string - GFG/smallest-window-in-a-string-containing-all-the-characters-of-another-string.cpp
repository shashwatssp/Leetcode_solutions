// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int map[26] = {0};
        int count =0;
        for(int i=0;i<p.size();i++)
        {
            if(map[p[i]-'a']==0)
            count++;
            
            map[p[i]-'a']++;
        }
        
        
        int start=0;
        int i=0;
        int j=0;
        int ans = INT_MAX;
        
        
        while(j<s.size())
        {
            map[s[j]-'a']--;
            if(map[s[j]-'a']==0)
            count--;
            
            if(count==0)
            {
                while(count==0)
                {
                   if(ans> j-i+1)
                   {
                       ans = j-i+1;
                       start =i;
                   }
                   
                   map[s[i]-'a']++;
                   if(map[s[i]-'a']==1)
                   count++;
                    
                    
                    
                    
                    i++;
                }
            }
            
            
            
            
            
            
            
            
            
            
            j++;
        }
        
        if(ans!= INT_MAX)
        return s.substr(start,ans);
        
        return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends