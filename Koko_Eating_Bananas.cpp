class Solution {
public:
    
    bool isPossible(vector<int> &piles, int k, int h){
        int hrs = 0;
        for(auto x: piles){
            if(x<=k) hrs++;
            else hrs+=(x+k-1)/k;
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int Hrs) {
        //predicate is isPossibleToEat()
        //FFFFTTTTT return first T
        
        int l = 1, h = *max_element(piles.begin(), piles.end());
        while(l<h){
            int m = l + (h-l)/2;
            if(isPossible(piles, m, Hrs)) h = m;
            else l = m+1;
        }
        if(isPossible(piles,l, Hrs)) return l;
        return -1;
        
    }
};