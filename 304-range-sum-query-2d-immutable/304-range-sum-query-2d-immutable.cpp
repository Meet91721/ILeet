class NumMatrix {
public:
    constexpr static int N = 250;
    // vector<vector<int>> mat(250,vector<int> (250));
    int mat[250][250];
    
    NumMatrix(vector<vector<int>>& matrix) {
        // mat.resize(matrix.size()+1, vector<int> (matrix[0].size() + 1));
        for(int i = 0; i < matrix.size()+1; i++){
            for(int j = 0; j < matrix[0].size()+1; j++){
                if(i == 0 || j == 0){
                    mat[i][j] = 0;
                }
                else{
                    mat[i][j] = mat[i-1][j]+mat[i][j-1]+matrix[i-1][j-1]-mat[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return mat[row2][col2] - mat[row1-1][col2] - mat[row2][col1-1] + mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */