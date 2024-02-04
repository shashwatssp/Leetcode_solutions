class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),[](vector<int>&a, vector<int>&b)
            {
                if(a[0]==b[0])
                    return a[1]>=b[1];
                else
                    return a[0]<=b[0];
            }); 
        
        // for(auto it: points)
        //     cout<<it[0]<<" "<<it[1]<<endl;
        
        int n = points.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
           for(int j=i+1;j<n;j++)
           {   
               
               if(points[i][0]<= points[j][0] && points[i][1]>=points[j][1])
               {
                   bool x = true;
                   
                   for(int k=i+1;k<j;k++)
                   {
                       if(points[k][1]>= points[j][1] && points[k][1]<= points[i][1])
                       {   
                           x = false;
                           break;
                       }
                   }
                   
                   if(x)
                   {
                       ans++;
                       // cout<<i<<" "<<j<<endl;
                   }
                   
               }
           }
        }
        
        return ans;
    }
};