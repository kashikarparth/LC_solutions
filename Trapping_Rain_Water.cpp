class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int lmax=0, rmax=0,res=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(lmax<height[l]) lmax=height[l];
                else res+=lmax-height[l];
                l++;
            }
            else
            {
                if(rmax<height[r]) rmax=height[r];
                else res+=rmax-height[r];
                r--;
            }
        }
        return res;
    }
};