class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
    
    map<char,int>freq;
    priority_queue<pair<int,int>>pq;    
    
    for(auto it : s) freq[it]++;
        
    for(auto it : freq) pq.push(it);   
        
    string ans="";
     
        while(pq.size())
        {   
            cout<<pq.size()<<endl;
            char c = pq.top().first;
            int cnt = pq.top().second;
            
            pq.pop();
            
            int k = min(repeatLimit,cnt);
            
            for(int i=0;i<k;i++)
            {
                ans+=c;
                cnt--;
            }
            
            if(cnt && pq.size())
            {
                char sec = pq.top().first;
                int snt = pq.top().second;
                pq.pop();
                ans+=sec;
                snt--;
                
                if(snt>0)
                pq.push(make_pair(sec,snt));
                
                cout<<sec<<" "<<snt<<endl;
            }
            
            if(cnt && c!=ans.back())
            pq.push(make_pair(c,cnt));
        }
        return ans;
    }
};