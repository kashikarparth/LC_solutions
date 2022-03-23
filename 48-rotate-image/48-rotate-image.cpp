class Solution {
public:
    void rotateOuter(vector<vector<int>> &matrix, int x, int n){
        int y = x;
        vector<int> v1,v2,v3,v4;
        for(int j = y; j < y + n; j++){
            v1.push_back(matrix[x][j]);
            v3.push_back(matrix[x+n-1][j]);
        }
        
        for(int i = x + n -1; i >=x; i--){
            v2.push_back(matrix[i][y+n-1]);
            v4.push_back(matrix[i][y]);
        }
        for(int i = x; i < x +n ; i++){
            matrix[i][y+n-1] = v1[i-x];
            matrix[i][y] = v3[i-x];
        }
        for(int j = y; j < y + n; j++){
            matrix[x+n-1][j] = v2[j-y];
            matrix[x][j] = v4[j-y];
        }
        
    }
    void rotate(vector<vector<int>>& matrix) {
        int t = matrix.size(), k = 0;
        while(t>1){
            rotateOuter(matrix, k, t);
            k+=1;
            t-=2;
        }
    }
};