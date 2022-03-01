class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        
        while(i<nums.size()){
            
            int j = i+1; //start from next
            bool f = false; //set flag
            while(j<nums.size() and nums[j] == nums[i]){
                if(f) break; //break on second
                else f = true; //set flag to true on first encounter
                j++;
            }
            
            while(j<nums.size() and nums[j] == nums[i]){
                nums.erase(nums.begin()+j);
            } //erase till equal after once encountered and ignored
            
            i = j; //set to next unequal
        }
        
        return nums.size();
        
    }
};