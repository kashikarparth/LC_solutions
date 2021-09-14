class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int maxsofar = nums[nums.size()-1];
        
        int axl = -1, axlind = -1;
        
        //atleast one on right is larger -> find axl
        for(int i = nums.size()-2; i>=0; i--){
            maxsofar = max(maxsofar,nums[i]);
            if(nums[i]<maxsofar){
                axl = nums[i];
                axlind = i;
                break;
            }
        }
        
        //if no axl, reverse sorted array max perm reached
        if(axl == -1){sort(nums.begin(),nums.end()); return;}
        
        //sort after axl for easy finding min larger element after axl
        sort(nums.begin()+axlind+1, nums.end());
        
        //swap min larger and axl
        for(int i = axlind+1; i<nums.size(); i++){
            if(nums[i] > axl){
                swap(nums[i], nums[axlind]);
                break;
            }
        }
        
        //sort after axl for next perm
        sort(nums.begin()+axlind+1, nums.end());
    }
};