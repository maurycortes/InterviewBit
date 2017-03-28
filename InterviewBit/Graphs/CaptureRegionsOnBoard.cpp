void dfs(vector<vector<char>> &board, int i, int j){  
  
    if(board[i][j] == 'X' || board[i][j] == '#')
        return;  
    board[i][j] = '#';   
  
    if(i > 0)
        dfs(board,i-1,j);  
    if(i < board.size()-1)
        dfs(board,i+1,j);  
    if(j > 0)
        dfs(board,i,j-1);  
    if(j < board[0].size() - 1)
        dfs(board,i,j+1);  
}   
  
void Solution::solve(vector<vector<char> > &board) {  
  
        if(board.empty())
            return;  
 
        int r = board.size(), c = board[0].size();  
 
        for(int i = 0; i < c; i++)
        {  
            dfs(board,0,i);
            dfs(board,r-1,i);
        }   
  
        for(int j = 1; j < r-1; j++)
        {
            dfs(board,j,0);  
            dfs(board,j,c-1);
        }   
       
        for(int i = 0; i < r; i++)
        { 
            for(int j = 0; j < c; j++)
            {  
                if(board[i][j] == '#')
                    board[i][j] = 'O';  
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';   
           }  
        }  
}