class Solution {
public:
    
    char find(char i, map<char,char> & parent)
    {
        if(parent[i]=='A')
            return char(i);
        return find(parent[i],parent);
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        map<char,char>parent;
        
        for(auto it: equations)
        {   
            
            char x = it[0];
            char y = it[3];
            

                parent[x] = 'A';
                parent[y] = 'A';
        }
        
        for(auto it: equations)
        {   
            if(it[1]=='!') continue;
            
            char x = find(it[0],parent);
            char y = find(it[3],parent);
            

            
            if(x!=y)
                parent[x] = y;
        }
        
        for(auto it: equations)
        {   
            
            
            if(it[1]=='=') continue;
            
            char x = it[0];
            char y = it[3];
            
            if(find(x,parent)==find(y,parent))
                return false;
        }
        
        return true;
    }
};