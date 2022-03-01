class Solution {
public:
    
    bool isPalin(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    
    
    string longestPalindrome(string s) {
        
        if(s.size() == 0) return "";
        
        int i = 0, j = 0;
        string ans = "";
        
        while(j<s.size()){
            //check if palindrome,increase window size
            if(isPalin(s, i , j)){
                if(ans.size() < j-i+1) ans = s.substr(i, j-i+1);
                i--;
                j++;
            }
            else{ //else slide
                i++;
                j++;
            }
            if(j>=s.size()) break;
            
            //offsetting window, to bring in bounds
            while(i<0){
                i++;
                j++; 
            }
            if(j>=s.size()) break; 
        }
        
        i = 0; j = 1;
        while(j<s.size()){
            //check if palindrome,increase window size
            if(isPalin(s, i , j)){
                if(ans.size() < j-i+1) ans = s.substr(i, j-i+1);
                i--;
                j++;
            }
            else{ //else slide
                i++;
                j++;
            }
            if(j>=s.size()) break;
            //offsetting window, to bring in bounds
            while(i<0){
                i++;
                j++; 
            }
            if(j>=s.size()) break; 
        }
       return ans; 
    }
};