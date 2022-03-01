class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        
        int maxP = nums[0], leastP = nums[0], ans = maxP;
        int i = 1;
        while(i<nums.size()){
            
            int maxPtemp;
            if(nums[i]==0){
                maxP = 0;
                leastP = 0;
            }
            
            else if(nums[i] > 0){
                maxP = max(maxP*nums[i], nums[i]);
                leastP = min(leastP*nums[i], nums[i]);
            }
            
            else{
                maxPtemp = max(leastP*nums[i], nums[i]);
                leastP = min(maxP*nums[i], nums[i]);
                maxP = maxPtemp;
            }
            
            ans = max(ans,maxP);
            i++;
        }
        return ans;
    }
};