class Solution {
public:
    string reverseWords(string s) {
        if(!s.size()) return s;
        vector<string> vec;
        string ans = "";
        
        int i = 0; 
        while(i<s.size()){
            if(s[i]==' '){
                if(ans.size()){
                    vec.push_back(ans);
                    ans = "";
                }
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        
        if(ans!="")vec.push_back(ans);
        
        reverse(vec.begin(),vec.end());    
        ans = "";
        
        for(auto x: vec){
            ans+=x;
            ans+=' ';
        }
        ans.pop_back();
        
            
        return ans;
    }
};