class Solution {
private:
    int row_len;
    int col_len;
    string s;
public:
    bool recur(vector<vector<char>>& board,int row,int col,int index)
    {
        if(index>=s.size() or row>=row_len or row<0 or col>=col_len or col<0 or board[row][col]==' ')
            return false;
        
        if(index==s.size()-1)return true;
        
        char ch= board[row][col];
        board[row][col]=' ';
        bool x=false;
        
        if(row+1<row_len and board[row+1][col] == s[index+1])
            x = x or recur(board, row+1,col,index+1);
        
        if(row-1 >=0 and board[row-1][col] == s[index+1])
            x = x or recur(board, row-1,col,index+1);
        
        if(col+1<col_len and board[row][col+1] == s[index+1])
            x = x or recur(board, row,col+1,index+1);
        
        if(col-1>=0 and board[row][col-1] == s[index+1])
            x = x or recur(board, row,col-1,index+1);
        
        board[row][col]=ch;
        
        return x;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        row_len=board.size();
        col_len=board[0].size();
        s=word; 
        
        for(int i=0;i<row_len;i++)
            for(int j=0;j<col_len;j++)
                if(board[i][j]==word[0] and recur(board,i,j,0))
                        return true;
                    
        
        return false;
    }
};