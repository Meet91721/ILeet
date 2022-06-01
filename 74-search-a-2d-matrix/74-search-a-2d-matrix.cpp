class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size()-1;
        while(hi-lo>1){
            int mid = (hi + lo) / 2;
            if(matrix[mid][0] > target){
                hi = mid - 1;
            }
            else{
                lo = mid;
            }
        }
        int row;
        if(matrix[lo][0] == target){
            return true;
        }
        if(matrix[hi][0] <= target){
            row = hi;
        }
        else{
            row = lo;
        }
        hi = matrix[row].size() - 1;
        lo = 0;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            if(matrix[row][mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid;
            }
        }
        if(matrix[row][lo] == target || matrix[row][hi] == target){
            return true;
        }
        return false;
    }
};