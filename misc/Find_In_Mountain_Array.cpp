/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        //increasing side search
        
        int start= 0, end = mountainArr.length()-1;
        int ans = INT_MAX;
        
        while(start<=end){
            
            int mid = (start+end)/2;
            if(mid >= mountainArr.length() or mid<0) break;
            
            int val_mid = mountainArr.get(mid);
            if(val_mid == target){
                ans = min(ans,mid);
                end = mid-1;
            }
            //decrease end if val_mid in decr region
            if(mid == mountainArr.length()-1 or val_mid>mountainArr.get(mid+1)){
                end = mid-1;
            }
            else{
                if(val_mid<target) start = mid+1;
                else end = mid-1;
            }
        }
        if(ans!=INT_MAX) return ans;
        //decreasing side search
        start= 0, end = mountainArr.length()-1;
        while(start<=end){
            
            int mid = (start+end)/2;
            if(mid >= mountainArr.length() or mid<0) break;
            int val_mid = mountainArr.get(mid);
            if(val_mid == target){
                ans = min(ans,mid);
                end = mid-1;
            }
            // increase start if val_mid in incr region
            if(mid == 0 or val_mid>mountainArr.get(mid-1)){
                start = mid+1;
            }
            
            else{
                if(val_mid<target) end = mid-1;
                else start = mid+1;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};