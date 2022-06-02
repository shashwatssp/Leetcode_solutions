class Solution {
    
    public:
    
    
    bool isVal(vector<vector<int>>& image, int i, int j ,int n, int m, int color)
    {
     if(i>=0 && i<n && j>=0 && j<m && image[i][j]==color)
         return true;
        
        return false;
    }
    
    
          void dfsrec(vector<vector<int>>&image, int i, int j, int n, int m, int color, int newColor)
            {
                image[i][j]=newColor;
                
             if(isVal(image,i+1,j,n,m,color))
                 dfsrec(image,i+1,j,n,m,color,newColor);
                 
                          if(isVal(image,i-1,j,n,m,color))
                 dfsrec(image,i-1,j,n,m,color,newColor);
                 
                             if(isVal(image,i,j+1,n,m,color))
                 dfsrec(image,i,j+1,n,m,color,newColor);
                 
                             if(isVal(image,i,j-1,n,m,color))
                 dfsrec(image,i,j-1,n,m,color,newColor);
                 
            }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        
        if(color==newColor)
            return image;
        
        int i = sr;
        int j = sc;
        
        dfsrec(image, sr, sc, n, m ,color, newColor);
        
        return image;
        
    }
};