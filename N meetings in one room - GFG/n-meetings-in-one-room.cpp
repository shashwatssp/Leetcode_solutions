// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    public:
    
   static bool comp(pair<int,int> p1, pair<int,int> p2)
    {
        if(p1.second == p2.second)
        {
            return p1.first<p2.first;
        }
        
        return p1.second<p2.second;    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        
        for(int i=0;i<n;i++)
        {
            meetings.push_back({start[i],end[i]});
        }
        
                    sort(meetings.begin(), meetings.end(), comp);
                    
                    
                    
                    
                            
        int ans=1;
        
        int limit = meetings[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(limit<meetings[i].first)
            {
                limit = meetings[i].second;
                ans++;
            }
        }
        
        return ans;
        
    }
    


};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends