class Solution {
public:
    bool convolution(vector<vector<char>> &board, unordered_set<int> &s){
        for(int row = 0; row <= 6; row+=3){
            for(int col = 0; col <=6; col+=3){
                s.clear();
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[row+i][col+j] == '.') continue;
                        else if(s.find(board[row+i][col+j]) == s.end()) s.insert(board[row+i][col+j]);
                        else return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> s;
        for(int i = 0; i < board.size(); i++){
            s.clear();
            for(auto x: board[i]){
                if(x == '.') continue;
                else if(s.find(x) == s.end()) s.insert(x);
                else return false;
            }
        }
        s.clear();
        for(int i = 0; i < board[0].size(); i++){
            s.clear();
            for(int j = 0; j <board.size(); j++){
                if(board[j][i] == '.') continue;
                else if(s.find(board[j][i])==s.end()) s.insert(board[j][i]);
                else return false;
            }
        }
        s.clear();
        return convolution(board, s);
    }
};