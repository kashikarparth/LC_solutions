class Solution {
public:
    int search(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        if(r1 < l1)
            return nums2[l2 + k - 1];
        if(r2 < l2)
            return nums1[l1 + k - 1];
        
        int m1 = (l1 + r1)/2;
        int m2 = (l2 + r2)/2;
        
        int c1 = m1 - l1 + 1;
        int c2 = m2 - l2 + 1;
        
        if(c1 + c2 <= k) {
            if(nums1[m1] <= nums2[m2])
                return search(nums1, nums2, m1 + 1, r1, l2, r2, k - c1);
            else
                return search(nums1, nums2, l1, r1, m2 + 1, r2, k - c2);
        }
        else {
            if(nums1[m1] >= nums2[m2])
                return search(nums1, nums2, l1, m1 - 1, l2, r2, k);
            else 
                return search(nums1, nums2, l1, r1, l2, m2 - 1, k);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int k = (n + m + 1)/2;
        
        if((n + m)&1) 
            return search(nums1, nums2, 0, n - 1, 0, m - 1, k);
        
        int a = search(nums1, nums2, 0, n - 1, 0, m - 1, k);
        int b = search(nums1, nums2, 0, n - 1, 0, m - 1, k + 1);
        
        return 1.0*(a + b)/2;
    }
};