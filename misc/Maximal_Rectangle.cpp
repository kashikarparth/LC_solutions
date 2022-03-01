class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> s;
        int maxa = 0, start_top = -1;
        
        for(int i = 0; i < heights.size(); i++){
            if(s.empty() or s.top().first<=heights[i]){
                s.push({heights[i], i});
                continue;
            }
            while(!s.empty() and s.top().first > heights[i]){
                maxa = max(maxa, (i-s.top().second)*s.top().first);
                start_top = s.top().second;
                s.pop();
            }
            s.push({heights[i],start_top});
        }
        
        while(!s.empty()){
            int new_ar = s.top().first*(heights.size()-s.top().second);
            maxa = max(maxa, new_ar);
            s.pop();
        }
        
        return maxa;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(!matrix.size()) return 0;
        
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++) m[i][j] = matrix[i][j]=='0'?0:1;
        }
        
        for(int i = 0; i < m.size(); i++){
            for(int j = 0; j < m[i].size(); j++){
                if(m[i][j] == 1){
                    if(i>0){
                        m[i][j] = m[i-1][j]+1;
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        for(auto x: m){
            ans = max(ans, largestRectangleArea(x));
        }
        return ans;
    }
};


//uses largest histogram row-wise on accumulated matrix of ones