class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=-1,l = -1;
        
        
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                f = mid;
                right = mid-1;
            }
            if(nums[mid]>target) right = mid-1;
            if(nums[mid]<target) left = mid+1;
        }
        
        
        left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid] == target){
                l = mid;
                left = mid+1;
            }
            if(nums[mid]>target) right = mid-1;
            if(nums[mid]<target) left = mid+1;
        }
        
        return {f,l};
    }
};