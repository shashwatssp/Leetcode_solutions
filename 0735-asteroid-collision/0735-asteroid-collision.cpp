class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        
        for(auto it: asteroids)
        {
            if(st.empty() || it>0)
                st.push(it);
            else
            {
                int x = -it;
                
                while(st.size() && st.top()>0 && st.top()<x)
                st.pop();
                
                if(st.empty() || st.top()<0)
                st.push(it);
                else if(st.top()==x)
                st.pop();    
            }
        }
        
        vector<int>ans;
        
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};