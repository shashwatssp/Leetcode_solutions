class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        set<int>set;
        q.push(start);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int top = q.front();
                q.pop();
                
                if(arr[top]==0)
                    return true;
                
                if(top-arr[top]>=0 && set.find(top-arr[top])==set.end())
                    q.push(top-arr[top]);
                
                if(top+arr[top]<arr.size() && set.find(top+arr[top])==set.end())
                    q.push(top+arr[top]); 
                
                set.insert(top);
            }
        }
        
        return false;
    }
};