class Solution {
public:
    
    int f(string s, vector<int>&dp, int ind){
        

        if(dp[ind]!=-1) return dp[ind];
        
        if(!s.size()) return 0;
  
        //base cases
        if(s.size()==1){
            if(s == "0"){
                dp[ind] = 0;
            }
            else dp[ind] = 1;
            return dp[ind];
        }
        
        //base cases
        
        if(s.size()==2){
            if(s == "00"){
                dp[ind] = 0;
                return dp[ind];
            }
            if(s[1] == '0'){
                if(s[0] == '1' or s[0] == '2') dp[ind] = 1;
                else dp[ind] = 0;
                return dp[ind];
            }
            
            if(s[0] == '0'){
                dp[ind] = 0; 
                return dp[ind];
            }
            
            if(s.compare("26")<=0){
                dp[ind] = 2;
            }
            
            
            else dp[ind]=1;
            return dp[ind];
        }
        
        if(s[s.size()-1] == '0'){
            if(s[s.size()-2] == '1' or s[s.size()-2] == '2') dp[ind] = f(s.substr(0,s.size()-2), dp, ind-2);
            else dp[ind] = 0;
            return dp[ind];
        }
        
        else{
            string l2 = s.substr(s.size()-2,2);
            dp[ind] = f(s.substr(0,s.size()-1), dp, ind-1); //take one
            if(l2.compare("26")<=0 and l2[0]!= '0') dp[ind] += f(s.substr(0,s.size()-2), dp, ind-2);//take two
            return dp[ind];
        }
        
        return dp[ind];
    }
    
    
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(s.size(), -1);
        return f(s, dp, s.size()-1);
        
    }
};