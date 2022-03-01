class Solution {
public:
    string say(string s){
        string ans = "";
        int i = 0;
        
        while(i<s.size()){
            int f = 0;
            int j = i;
            
            while(j<s.size()){
                if(s[j] == s[i]){
                    f++;
                    j++;
                }
                else break;
            }
            
            ans+=to_string(f);
            ans+=s[i];
            i = j;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        if(n==1) return to_string(1);
        else return say(countAndSay(n-1));
    }
};