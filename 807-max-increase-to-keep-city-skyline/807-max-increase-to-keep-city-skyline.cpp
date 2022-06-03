class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>row_max(grid.size());
        vector<int>col_max(grid[0].size());
        
        for(int i = 0; i < grid.size(); i++){
            int mx = INT_MIN;
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] > mx)
                    mx = grid[i][j];
            }
            row_max[i] = mx;
        }
        
        for(int i = 0; i < grid[0].size(); i++){
            int mx = INT_MIN;
            for(int j = 0; j < grid.size(); j++){
                if(grid[j][i] > mx)
                    mx = grid[j][i];
            }
            col_max[i] = mx;
        }
        
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] < min(row_max[i], col_max[j])){
                    // cout << grid[i][j] << '\n';
                    res+= min(row_max[i], col_max[j]) - grid[i][j];
                }
            }
        }
        
        // for(auto it: col_max){
        //     cout << it << "  ";
        // }
        // cout << '\n';
        // for(auto it: row_max){
        //     cout << it << "  ";
        // }
        return res;
    }
};