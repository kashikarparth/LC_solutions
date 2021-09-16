class Solution {
public:
    
    int roblinear(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 0);
        
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[dp.size()-1];
    }
    
    int rob(vector<int>& nums) {
        
        int ans = 0;
        vector<int> temp;
        
        if(!nums.size()) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return nums[0]>nums[1]?nums[0]:nums[1];
        
        
        for(int i = 0; i < nums.size(); i++){
            temp.clear();
            
            if(i==0){
                for(int k = 2; k <= nums.size()-2; k++) temp.push_back(nums[k]);
            }
            
            else if(i == nums.size()-1){
                for(int k = 1; k <= nums.size()-3; k++) temp.push_back(nums[k]);
            }
            
            else{
                for(int k = i+2; k < nums.size(); k++) temp.push_back(nums[k]);
                for(int k = 0; k < i-1; k++) temp.push_back(nums[k]);
            }
            
            ans = max(ans, nums[i] + roblinear(temp));
        }
        
        return ans;
    }
};