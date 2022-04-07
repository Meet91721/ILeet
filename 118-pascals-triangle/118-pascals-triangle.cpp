class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        for(int i = 0; i < numRows-1; i++){
            vector<int>temp(i+2);
            temp[0]=1;
            temp[i+1]=1;
            for(int j = 0; j < i; j++){
                temp[j+1]=res[i][j]+res[i][j+1];
            }
            res[i+1]=temp;
        }
        return res;
    }
};