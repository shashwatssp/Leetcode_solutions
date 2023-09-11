class Solution {
public:
    
    int find(int i, map<int,int> & parent)
    {
        if(parent[i]==-1)
            return i;
        return find(parent[i],parent);
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        map<int,int>parent;
        
        for(auto it: equations)
        {   
            
            int x = it[0]-'a';
            int y = it[3]-'a';
            
                parent[x] = -1;
                parent[y] = -1;
        }
        
        for(auto it: equations)
        {   
            if(it[1]=='!') continue;
            
            int x = find(it[0]-'a',parent);
            int y = find(it[3]-'a',parent);
            
            
            if(x!=y)
                parent[x] = y;
        }
       
        for(auto it: equations)
        {   
            if(it[1]=='=') continue;

            
            
            int x = it[0]-'a';
            int y = it[3]-'a';
            
            if(find(x,parent)==find(y,parent))
                return false;
        }
        
        return true;
    }
};