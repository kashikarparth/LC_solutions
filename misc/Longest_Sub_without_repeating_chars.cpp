class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        if(s.size()<=1) return s.size();
        int i = 0, j = 0;
        int ans = INT_MIN;
        
        while(i<s.size() and j<s.size()){
            if(m.find(s[j]) !=m.end()){
                while(i<m[s[j]] + 1){
                    m.erase(s[i]);
                    i++;
                }
                m[s[j]] = j;
            }
            else{
                m[s[j]] = j;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};