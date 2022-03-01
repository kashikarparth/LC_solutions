class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[i].size()-1;
        while(i>=0 and j>=0 and i<matrix.size() and j<matrix[i].size()){
            if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]<target) i++;
            else return true;
        }
        
        return false;
    }
};