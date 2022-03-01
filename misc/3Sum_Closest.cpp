class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size()-2; i++){
            int l = i+1;
            int h  = nums.size()-1;
            while(l<h){
                int s = nums[i] + nums[l] + nums[h];
                if(abs(s-target)<abs(ans-target)){
                    ans = s;
                }
                if(s==target) return s;
                if(s>target) h--;
                else l++;
            }
        }
        return ans;
    }
};  