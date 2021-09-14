class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> ps(m, vector<int>(n,0));
        
        ps[0][0] = grid[0][0];
        
        for(int i = 1; i < n; i++){
            ps[0][i] = ps[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < m; i++){
            ps[i][0] = ps[i-1][0] + grid[i][0];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ps[i][j] = min(ps[i-1][j], ps[i][j-1]) + grid[i][j];
            }
        }
        
        return ps[m-1][n-1];
        
    }
};