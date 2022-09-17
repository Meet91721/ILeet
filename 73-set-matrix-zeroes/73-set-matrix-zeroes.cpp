class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cr = 0, ct = 0;
        for(int i= 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0)
                cr = 1;
        }
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0)
                ct = 1;
        }
        for(int i = 1; i < matrix[0].size(); i++){
            for(int j = 1; j < matrix.size(); j++){
                if(matrix[j][i] == 0){
                    matrix[j][0] = 0;
                    matrix[0][i] = 0;
                }
            }
        }
        for(int i = 1; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                for(int j = 1; j < matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(cr)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(ct)
            for(int i = 0; i< matrix.size(); i++)
                matrix[i][0] = 0;
    }
};