class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        for(int i = 0; i < obstacleGrid.size(); i++){
            for(int j = 0; j < obstacleGrid[i].size(); j++){
                obstacleGrid[i][j]*=-1;
            }
        }
        
   
        
        obstacleGrid[0][0] = obstacleGrid[0][0]==-1?-1:1;
        
        for(int i = 0 ; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]!=-1) obstacleGrid[0][i] = 1;
            else break;
        }
        
        for(int i = 0 ; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]!=-1) obstacleGrid[i][0] = 1;
            else break;
        }
        
        
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[i].size(); j++){
                if(obstacleGrid[i][j]!=-1){
                    if(obstacleGrid[i-1][j]!=-1) obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                    if(obstacleGrid[i][j-1]!=-1) obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                }
            }
        }
        
        for(auto it: obstacleGrid){
            for(auto x: it){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]>0?obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]:0;
};
    
};