class Solution {
public:
    
    vector<vector<int>> dp;
    unordered_map<int,int> m;
    
    bool calc(int posi, vector<int> &stones, int lastj){
    
        //reached end
        if(posi == stones.size()-1){
            return true;
        }
        
        //if visited return it
        if(lastj >=0 and dp[posi][lastj]>=0) return dp[posi][lastj];
        
        //starting jump
        if(posi == 0){
            int stone = stones[posi];
            int next = stone+1;
            if(m.find(next) == m.end()){
                return false;
            }
            return calc(m[next], stones, 1);
        }
        
        int stone = stones[posi];
        vector<int> next = {stone+lastj+1, stone+lastj, stone+lastj-1};
        bool ans = false;
        for(auto x: next){
            if(m.find(x) == m.end() or x==stone) continue;
            ans = ans or calc(m[x], stones, x - stone);
            if(ans){
                dp[posi][lastj] = 1;
                return dp[posi][lastj];
            }
        }
        
        dp[posi][lastj] = 0;
        return dp[posi][lastj];
    }
    
    bool canCross(vector<int>& stones) {
        for(int i =0; i < stones.size(); i++){
            m[stones[i]] = i;
        }
        
        dp = vector<vector<int>>(stones.size(), vector<int>(stones.size(),-1));
        return calc(0, stones, -1);
    }
};