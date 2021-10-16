class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        int ans = INT_MAX;
        int start = 0, end = nums.size()-1;
        if(nums[end]>nums[start]) return nums[start];
        
       while(start<=end){
           int mid = (start+end)/2;
           ans = min(ans, min(min(nums[start],nums[end]), nums[mid]));
           if(nums[mid]>nums[start]){
               start = mid+1;
           }
           else if(nums[mid]<nums[end]){
               end = mid-1;
           }
           else end--;
       }
        return ans;
    }
};