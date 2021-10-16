class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());

        int i=0;

        while(i < nums.size())
        {
            int target = nums[i]*-1;
            int j = i+1;
            int k = nums.size()-1;


            while(j<k)
            {
                if(nums[j]+nums[k] == target)
                {
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    k--;

                    while(j < k and nums[j] == nums[j-1]) j++;
                    while(k > j and nums[k] == nums[k+1]) k--;

                }
                else if(nums[j]+nums[k] > target) k--;
                else j++;
            }

            i++;

            while(i<nums.size() and nums[i] == nums[i-1]) i++;
        }

        return ans;

    }
};