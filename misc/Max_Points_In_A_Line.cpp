class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        unordered_map<int, unordered_map<double,int>> m;
        int ans = INT_MIN;
    
        if(!points.size()) return 0;
        if(points.size()==1) return 1;
        
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                double slope;
                if(points[i][0] == points[j][0]) slope = INT_MAX;
                else slope  = double(points[i][1] - points[j][1])/double(points[i][0] - points[j][0]);
                m[i][slope]++;
                m[j][slope]++;
                ans = max(ans, m[i][slope]);
                ans = max(ans, m[j][slope]);
            }        
        }
        
       return ans+1;
    }
};