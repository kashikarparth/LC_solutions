class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        if(!prices.size() or prices.size()==1) return 0;
        
        vector<int>dp(prices.size(),0);
        
        int mint = prices[0] - dp[0];
        
        for(int i = 1; i < prices.size(); i++){
            dp[i] = max(0,dp[i-1]);
            dp[i] = max(dp[i], prices[i] - mint);
            mint = min(mint, prices[i] - dp[i]);
        }
        return dp[prices.size()-1];
    }
};