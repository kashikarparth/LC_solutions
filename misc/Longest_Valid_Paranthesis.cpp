class Solution {
public:
    int longestValidParentheses(string s) {
        if(!s.size()) return 0;
        
        stack<pair<char,int>> st;
        int i = 0;
        
        while(i<s.size()){
            if(s[i] == '('){
                st.push({'(', i});
            }
            else{
                if(st.empty() or st.top().first!='(') st.push({')',i});
                else st.pop();
            }
            i++;
        }
        
        int end = s.size()-1;
        int l = INT_MIN;
        
        if(st.empty()) return s.size();
        
        while(!st.empty()){
            l = max(l, end-st.top().second);
            end = st.top().second-1;
            st.pop();
        }
        
        l = max(l, end+1);
        
        return l;
    }
};