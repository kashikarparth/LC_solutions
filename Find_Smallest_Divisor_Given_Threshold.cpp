class Solution {
public:
    
    bool predicate(int mid, vector<int> &nums, int thresh){
        int sum = 0;
        for(auto x: nums){
            sum+=ceil((float)x/(float)mid);
        }
        return sum<=thresh;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        ///predicate -> sum of div <=threshold
        ///FFFFFFTTT -> find first T
        
        int l  = 1, h = *max_element(nums.begin(), nums.end());
        
        while(l<h){
            int mid = l + (h-l)/2;
            //cout<<mid<<" "<<predicate(mid, nums, threshold)<<endl;
            if(predicate(mid, nums, threshold)) h = mid;
            else l = mid+1;
        }
        if(predicate(l, nums, threshold)) return l;
        else return -1;
        
    }
};