class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        
        int n = arr.size();
        
        priority_queue<pair<long long, pair<int,int> >>pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                pq.push({{-arr[i]*100000000000000/arr[j]},{i,j}});
            }
        }
        
        int num = k-1;
        
        while(num--)
        {
            pq.pop();
        }
        
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        
        return {arr[x],arr[y]};
    }
};