class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        
        int start = 0, end = matrix.size()-1, mid;
        while(start<=end){
            mid = (start+end)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0]>target) end = mid-1;
            else start=mid+1;
        }
        
        int searchRow;
        if(matrix[mid][0]<target){
            searchRow = mid;
        }
        else searchRow = mid-1;
        
        if(searchRow<0) return false;
        
        start = 0, end = matrix[searchRow].size()-1, mid;
        while(start<=end){
            mid = (start+end)/2;
            if(matrix[searchRow][mid] == target) return true;
            else if(matrix[searchRow][mid]>target) end = mid-1;
            else start=mid+1;
        }
        return false;
    }
};