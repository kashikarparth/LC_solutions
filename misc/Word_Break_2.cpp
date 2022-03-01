class Solution {
public:
    
    vector<string> call(unordered_map<int,vector<string>> &dp, string &s, int start_ind, vector<string>& wordDict){
        if(start_ind>=s.size()) return {""};
        if(dp.find(start_ind)!=dp.end()) return dp[start_ind];
        
        vector<string> poss;
        
        for(auto x: wordDict){
            
            if(start_ind+x.size()-1>s.size()) continue;
            
            if(s.substr(start_ind,x.size()) == x){
                vector<string> temp  = call(dp, s, start_ind+x.size(), wordDict);
                for(auto y: temp){
                    string st = x;
                    if(y!="") st+=' ';
                    st+=y;
                    poss.push_back(st);
                }
            }
            
        }
        
        dp[start_ind] = poss;
        return dp[start_ind];
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,vector<string>> dp;
        return call(dp, s, 0, wordDict);
    }
};