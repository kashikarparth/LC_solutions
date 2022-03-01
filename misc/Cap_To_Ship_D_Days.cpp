class Solution {
public:
    bool pred(vector<int>& weights, int cap, int days){
        int t_days = 0;
        int i = 0;
        int ship_cap = cap;
        
        while(i<weights.size()){
            t_days++;
            ship_cap = cap;
            while(i<weights.size()){
                if(weights[i]<=ship_cap and ship_cap){
                    ship_cap-=weights[i];
                    i++;
                }
                else break;
            }
        }
        return t_days<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()), h = accumulate(weights.begin(),weights.end(),0);
        
        while(l<h){
            int m = l + (h-l)/2;
            if(pred(weights,m,days)) h = m;
            else l = m+1;
        }
        if(pred(weights,l,days)) return l;
        return -1;
        
    }
};