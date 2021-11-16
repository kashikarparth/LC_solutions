class Solution {
public:
    
    int mutated_sum(vector<int> &arr, int m){
        int s = 0;
        for(auto x: arr) s+=x>m?m:x;
        return s;
    }
    
    int findBestValue(vector<int>& arr, int target) {
        //predicate is mutated sum>=target
        //FFFFFTTTTT get first T
        //check if ==target, if not check for one less than first T and return best
        
        int l = 0, h = *max_element(arr.begin(), arr.end());
        
        while(l < h){
            int m = l + (h-l)/2;
            if(mutated_sum(arr,m)>=target) h = m;
            else l = m+1;
        }
        
        if(mutated_sum(arr,l)<target) return *max_element(arr.begin(),arr.end());
        
        return abs(mutated_sum(arr,l-1)-target)<=abs(mutated_sum(arr,l)-target)?l-1:l;
        
    }
};