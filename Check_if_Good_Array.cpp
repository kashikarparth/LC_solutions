class Solution {
public:
      //aX + bY = k has __integer solution__ (X, Y) if k is multiple of gcd(a, b)
    //here k=1 so __gcd should be 1
    //Subset has gcd 1 == whole array should have 1
    bool isGoodArray(vector<int>& nums) {
        int k=nums[0];
        for(auto i:nums){
            k=__gcd(k,i);
        }
        return k==1;
    }
};