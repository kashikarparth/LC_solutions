class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, m, ax=0;
        
        if(nums.size()==1) return nums[0];
    
        while(s<=e){
            m = (s+e)/2;
            if(m<nums.size()-1 and nums[m]>nums[m+1]){
                return nums[m+1];
            }
            if(m>0 and nums[m]<nums[m-1]){
                return nums[m];
            }
            if(nums[m]>nums[e]) s = m+1;
            else e = m-1;
        }
        
        return nums[0];
    }
};