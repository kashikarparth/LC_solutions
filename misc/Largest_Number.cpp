class Solution {
public:
    bool static cmp(int a, int b){
        return stoll(to_string(a)+to_string(b)) > stoll(to_string(b)+to_string(a));
    }
    
    string removeTrailingZeros(string s){
        while(s.size() and s[0]=='0') s.erase(0);
        if(!s.size()) s="0";
        return s;
    }
    
    string largestNumber(vector<int>& nums) {
        
        string ans = "";
        sort(nums.begin(),nums.end(), cmp);
        for(auto x: nums) ans+=to_string(x);
        return removeTrailingZeros(ans);
        
    }
};