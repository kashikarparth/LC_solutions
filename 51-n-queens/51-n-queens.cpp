class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>answer;
        vector<vector<char>> grid(n,vector<char>(n,'.'));
        
        nQueen(grid,0,n,answer);
        return answer;
        
    }

    void nQueen(vector<vector<char>>&grid,int curr_row,int n,vector<vector<string>>&answer){
        if(curr_row==n){
            vector<string> tempAns = populate(grid,n);
        answer.push_back(tempAns);
            return;
        }
        for(int curr_col=0;curr_col<n;curr_col++){
             if(isValid(grid,curr_row,curr_col,n)){
                grid[curr_row][curr_col]='Q';
                nQueen(grid,curr_row+1,n,answer) ;
                grid[curr_row][curr_col]='.';
            }
            
        }
        return;
       
    }

    vector<string>populate(vector<vector<char>>&grid,int n){
        vector<string>ans;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=grid[i][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }

    bool isValid(vector<vector<char>>&grid,int curr_row,int curr_col,int n){
        return isRowValid(grid,curr_row,n)&&isColValid(grid,curr_col,n)&&isDiagonalValid(grid,curr_row,curr_col,n);
            
        }
         

    bool isRowValid(vector<vector<char>>&grid,int curr_row,int n){
        
        for(int j=0;j<n;j++){
            if(grid[curr_row][j]=='Q'){
                return false;
            }            
        }
        return true;
    }

    bool isColValid(vector<vector<char>>&grid,int curr_col,int n){
        
        for(int i=0;i<n;i++){
            if(grid[i][curr_col]=='Q'){
                return false;
            }
            
        }
        return true;
    }

    bool isDiagonalValid(vector<vector<char>>&grid,int curr_row,int curr_col,int n)
     {
        int i = curr_row;
        int j = curr_col;
        while(i>=0 && j>=0) // first diag
        {
            if(grid[i][j]=='Q') return false;
            i--;
            j--;
        }
         i = curr_row;
         j = curr_col;
        while(i>=0 && j<n) // second diag
        {
            if(grid[i][j]=='Q') return false;
            i--;
            j++;
        }
         i = curr_row;
         j = curr_col;
        while(i<n && j>=0) // third diag
        {
            if(grid[i][j]=='Q') return false;
            i++;
            j--;
        }
         i = curr_row;
         j = curr_col;
        while(i<n && j<n) // fourth diag
        {
            if(grid[i][j]=='Q') return false;
            i++;
            j++;
        }
        return true;
    }
};