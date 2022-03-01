class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0]<b[0]) return true;
        if(a[0] == b[0] and a[1]<b[1]) return true;
        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        // int i = 0;
        // unordered_map<int, pair<int,int>> m;
        
        // while(i<envelopes.size()){
        //     int s = i;
        //     int e = i;
        //     while(e<envelopes.size() and envelopes[e][0] == envelopes[s][0]){
        //         e++;
        //     }
        //     m[envelopes[i][0]] = {s,e-1};
        //     i = e;
        // }
        
        vector<int> dp(envelopes.size(), 1);
        
        //go through every envelope, for all lower heights get closest width with BS and do dp accumulation.
        
        for(int i = 1 ; i < dp.size() ;i++){
            for(int j = 0; j < i; j++){
                if(envelopes[j][0] < envelopes[i][0] and envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        
        
        
        return *max_element(dp.begin(), dp.end());
    }
};