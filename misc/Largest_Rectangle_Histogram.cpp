class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> s;
        int maxa = 0, start_top = -1;
        
        for(int i = 0; i < heights.size(); i++){
            
            //keep pushing all right->extendable rectangles heightwise (increasing)
            if(s.empty() or s.top().first<=heights[i]){
                s.push({heights[i], i});
                continue;
            }
            
            //as soon as decreasing height encountered, pop till monotonic while calculating max contributions from greater heights, of widths till smaller encountered.
            while(!s.empty() and s.top().first > heights[i]){
                maxa = max(maxa, (i-s.top().second)*s.top().first);
                start_top = s.top().second;
                s.pop();
            }
            
            //push the smaller height with starting index as left as possible (largest possble contribution from this height)
            s.push({heights[i],start_top});
        }
        
        
        //all remaining heights are extendable to end of array from starting index
        while(!s.empty()){
            int new_ar = s.top().first*(heights.size()-s.top().second);
            maxa = max(maxa, new_ar);
            s.pop();
        }
        
        return maxa;
        
    }
};