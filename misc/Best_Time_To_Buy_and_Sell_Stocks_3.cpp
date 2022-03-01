class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minp = INT_MAX, maxdp1 = INT_MIN, maxdp2 = INT_MIN, mint = INT_MAX, ans = INT_MIN;
        
        for(auto x: prices){
            
            minp = min(minp, x);
            
            maxdp1 = max(maxdp1, x - minp);
            
            mint = min(mint, x - maxdp1);
            
            ans = max(ans, max(x - mint, maxdp1));
        }
        return max(ans,0);
    }
};