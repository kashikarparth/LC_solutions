class Solution {
public:
    
    void f(vector<string> &ans, string s, int open_used, int close_used, int n){
        if(close_used == n){
            ans.push_back(s);
            return;
        }
        if(open_used < n){
            f(ans,s+'(',open_used+1, close_used, n);
        }
        if(close_used < open_used){
            f(ans,s+')',open_used,close_used+1,n);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        f(ans, s, 0,0,n);
        return ans;
    }
};