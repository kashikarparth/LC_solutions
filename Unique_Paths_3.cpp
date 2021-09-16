class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> vis, int i, int j, int &ans){
        
        vis[i][j] = true;
        
        if(grid[i][j] == 2){
            //missed a square
            for(int k = 0; k < vis.size(); k++){
                for(int l = 0; l < vis[k].size(); l++){
                    if(!vis[k][l] and grid[k][l]!=-1) return;
                }
            }
            // all visited
            ans++;
        }
        else{
            if( i+1 < grid.size() and grid[i+1][j]!=-1 and !vis[i+1][j]) dfs(grid, vis, i+1, j, ans);
            if( j+1 < grid[i].size() and grid[i][j+1]!=-1 and !vis[i][j+1]) dfs(grid, vis, i, j+1, ans);
            if( j-1 >=0 and grid[i][j-1]!=-1 and !vis[i][j-1]) dfs(grid, vis, i, j-1, ans);
            if( i-1 >=0 and grid[i-1][j]!=-1 and !vis[i-1][j]) dfs(grid, vis, i-1, j, ans);
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        if(!grid.size()) return 0;
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(),false));
        int ans = 0;
        
        int i, j;
        
        for(int k = 0; k < grid.size(); k++){
            for(int l = 0; l < grid[k].size(); l++){
                if(grid[k][l] == 1){
                    i = k;
                    j = l;
                }
            }
        }
        
        //send in starting square
        dfs(grid, vis, i , j, ans);
        
        return ans;
    }
};