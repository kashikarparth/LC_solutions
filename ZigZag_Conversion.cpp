class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<vector<char>> diag(numRows,vector<char>());
        int where = 0;
        int ind = 0;
        bool rev = false; 
        
        if(numRows == 1) return s;
        
        while(ind<s.size()){
            diag[where].push_back(s[ind]);
            if(where == numRows - 1 and rev==false){
                rev = true;
            }
            if(where == 0 and rev == true){
                rev = false;
            }         
            if(rev) where--;
            else where++;            
            ind++;
        }
        
        s = "";
        
        for(auto it: diag) for(auto ch: it) s+=ch;        
        return s;
    }
};