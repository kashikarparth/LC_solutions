class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0, e = nums.size()-1, m, ax=0;
        
        if(nums.size()==1) return nums[0]==target?0:-1;
        
        //find axle pt
        while(s<=e){
            m = (s+e)/2;
            if(nums[m] == target) return m;
            
            if(m<nums.size()-1 and nums[m]>nums[m+1]){
                ax = m;
                break;
            }
            if(m>0 and nums[m]<nums[m-1]){
                ax = m-1;
                break;
            }
            if(nums[m]>nums[e]) s = m+1;
            else e = m-1;
        }
        
        
        s = 0; e = ax;
        
        //first segment
        while(s<=e){
            m = (s+e)/2;
            if(nums[m] == target) return m;
            if(nums[m]<target) s = m+1;
            else e = m-1;
        }
        
        s = ax+1, e = nums.size()-1;
        
        //second segment
        while(s<=e){
            m = (s+e)/2;
            if(nums[m] == target) return m;
            if(nums[m]<target) s = m+1;
            else e = m-1;
        }
    
        return -1;
    }
};