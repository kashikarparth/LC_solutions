class Solution {
public:
    int find(int x, unordered_map<int,int> &m){
        if(m[x] == x) return x;
        m[x] = find(m[x], m);
        return m[x];
    }
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_map<int,int> m;
        int ans = 1;
        for(auto x: nums) m[x] = x;
        for(auto x: nums) if(m.find(x-1) != m.end()) m[x] = x-1;
        for(auto x: nums) ans = max(ans, x - find(x,m) + 1);
        return ans;
    }
};