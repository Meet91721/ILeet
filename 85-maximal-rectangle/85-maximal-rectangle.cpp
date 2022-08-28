class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<vector<int>>matrix(mat.size(),vector<int>(mat[0].size()));
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]=='1')
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
                if(i){
                    matrix[i][j] = (matrix[i-1][j]+matrix[i][j])*matrix[i][j];
                }
            }
        }
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix[0].size(); j++)
        //         cout << matrix[i][j] << " ";
        //     cout << '\n';
        // }
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            stack<pair<int,int>>stk;
            vector<int>left(matrix[0].size(),0);
            for(int j = 0; j < matrix[0].size(); j++){
                while(stk.size() > 0 && stk.top().first>=matrix[i][j])
                    stk.pop();
                if(stk.size())
                    left[j]=stk.top().second+1;
                else
                    left[j]=0;
                stk.push({matrix[i][j],j});
            }
            while(stk.size())
                stk.pop();
            for(int j = matrix[0].size()-1; j >= 0; j--){
                while(stk.size() && stk.top().first>=matrix[i][j])
                    stk.pop();
                if(stk.size()){
                    res = max(res,matrix[i][j]*(stk.top().second-left[j]));
                }
                else{
                    res = max(res,matrix[i][j]*((int)matrix[0].size()-left[j]));
                }
                stk.push({matrix[i][j],j});
            }
        }
        return res;
    }
};