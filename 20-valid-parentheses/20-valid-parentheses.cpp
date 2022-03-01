class Solution {
public:
    bool isValid(string s1) {
        stack<char> s;
        for(auto x: s1){
            if(x == '(' or x == '{' or x=='[') s.push(x);
            else if(x == ')'){
                if(s.empty()) return false;
                if(s.top() == '(') s.pop();
                else return false;
            }
            else if(x == ']'){
                if(s.empty()) return false;
                if(s.top() == '[') s.pop();
                else return false;
            }
            else if(x == '}'){
                if(s.empty()) return false;
                if(s.top() == '{') s.pop();
                else return false;
            }
        }
        return s.empty();
    }
};