class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int area = min(height[i], height[j])*(j-i);
        while(j>i){
            if(height[i]<height[j]) i++;
            else j--;
            area = max(area, min(height[i],height[j])*(j-i));
        }
        return area;
    }
};