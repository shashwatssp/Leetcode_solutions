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
            
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<it[3]<<" "<<endl;
            cout<<x<<" "<<y<<endl;
            
            if(x!=y)
                parent[x] = y;
        }
        cout<<"------------"<<endl;
        for(auto it: equations)
        {   
            if(it[1]=='=') continue;
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<it[3]<<" "<<endl;
            cout<<parent[it[0]]<<" "<<parent[it[3]]<<endl;
            
            
            int x = it[0]-'a';
            int y = it[3]-'a';
            
            if(find(x,parent)==find(y,parent))
                return false;
        }
        
        return true;
    }
};