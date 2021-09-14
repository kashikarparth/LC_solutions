class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i = 0; i <nums.size()-1; i++){
            if(i>reachable) break;
            reachable = max(reachable, nums[i]+i);
            if(reachable>=nums.size()-1) return true;
        }
        if(reachable>=nums.size()-1) return true;
        return false;
    }
};