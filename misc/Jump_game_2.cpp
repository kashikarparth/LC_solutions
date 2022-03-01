class Solution {
public:
    int jump(vector<int>& nums) {

        int fr = nums[0];
        int jumps = 0;
        int i = 0;
        
        while(i<nums.size()-1){
            
            if(fr>=nums.size()-1) return jumps+1;
            
            //look in possible jumps
            int fr_temp = fr;
            int max = nums.size();
            
            //among all possible jumps. choose one which increases reach max    
            for(int j = i; j <=fr_temp; j++){
                if(nums[j]+j>fr){
                    fr = nums[j]+j;
                    max = j;
                }
            }
            
            i = max;

            jumps++;
            fr = i + nums[i];
            
        }
        
        return jumps;
    }
};