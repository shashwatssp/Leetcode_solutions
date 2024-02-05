class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        
        if(n!=target.size()) return false;
        
        int sl=0,sr=0,tl=0,tr=0;
        
        for(auto it : start)
            if(it=='L') sl++;
            else if(it=='R') sr++;
        
        for(auto it : target)
            if(it=='L') tl++;
            else if(it=='R') tr++; 
        
        if(sl!=tl || sr!=tr) return false;
        
      
      int j=0;
      for(int i=0;i<n;i++)
      {
          if(target[i]=='_') continue;
          
          
          if(j==n) return false;
          
          if(target[i]=='L')
          {
              while(j<n && start[j]=='_') j++;
              
              if(j<i) return false;
              
              if(j<n && start[j]!='L') return false;
              else j++;
          }
          else
          {
              while(j<i && start[j]=='_')j++;
              
             
              if(j<n && start[j]!='R') return false;
              else j++;
          }
      }
          
       return true; 
    }
    
    
};