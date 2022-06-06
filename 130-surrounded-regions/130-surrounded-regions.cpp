class Solution {
    

public:
  void convert(vector<vector<char>>&board) 
      
  {
      
      int n = board.size();
      int m = board[0].size();
      
     for(int i=0;i<n;i++)
        {   
     for(int j=0;j<m;j++)
     {

       if(board[i][j]=='B')
          board[i][j]='O';
         else if (board[i][j]=='O')
             board[i][j]='X';
     }
            
        }
  }
    
    
 bool isVal(int i, int j , int n, int m , vector<vector<char>>&board)
 {
if(i>=0 && j>=0 && i<n && j<m && board[i][j]=='O')
    return true;
     
     return false;
 }
    
    
 void dfs(int i , int j , int n, int m , vector<vector<char>>&board)
 {
     board[i][j]='B';
     
     if(isVal(i+1,j,n,m,board))
         dfs(i+1,j,n,m,board);
     
          if(isVal(i-1,j,n,m,board))
         dfs(i-1,j,n,m,board);
     
          if(isVal(i,j-1,n,m,board))
         dfs(i,j-1,n,m,board);
     
          if(isVal(i,j+1,n,m,board))
         dfs(i,j+1,n,m,board);
     
 } 
    
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<char>> ans;
        
        for(int i=0;i<n;i++)
        {
            int j = 0;
            
            if(board[i][j]=='O')
                dfs(i,j,n,m,board);
                
             j = m-1;
            
            if(board[i][j]=='O')
                dfs(i,j,n,m,board);
        }
        
        for(int j=0;j<m;j++)
        {
            int i = 0;
            
            if(board[i][j]=='O')
                dfs(i,j,n,m,board);
                
            i = n-1;
            
            if(board[i][j]=='O')
                dfs(i,j,n,m,board);
        }                
        
        
convert(board);
    
    }
};