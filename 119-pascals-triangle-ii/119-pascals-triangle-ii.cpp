class Solution {
public:
    
    
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex+1);
        pascal[0].push_back(1);
        for(int i = 0; i < rowIndex; i++){
            vector<int> temp(i+2);
            temp[0]=1;
            temp[i+1]=1;
            for(int j = 0; j < i; j++){
                temp[j+1]=pascal[i][j]+pascal[i][j+1];
                // temp[j+1]=0;
            }
            pascal[i+1] = temp;
        }
        return pascal[rowIndex];
    }
};