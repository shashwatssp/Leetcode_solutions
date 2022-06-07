// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comp ( Job J1 , Job J2)
{
    return J1.profit> J2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        
        int deadline =0;
        
        for(int i=0;i<n;i++)
        deadline = max(deadline, arr[i].dead);
        
        bool flag[deadline+1]={false};
        
        vector<int> ans;
        int jobs=0;
        int profit =0;
        
        for(int i=0;i<n;i++)
        {
            for(int j = arr[i].dead; j>0; j--)
            {
                if(flag[j]==false)
                {
                    flag[j]=true;
                    profit+=arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        
        ans.push_back(jobs);
        ans.push_back(profit);
        
        return ans;
    
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends