class Solution {
public:
    
    constexpr static int N = 600;
    
    int visited[N][N];
    
    bool traversal(vector<vector<int>>&grid1, vector<vector<int>>&grid2, int r, int c){
        if(r < 0 || c < 0 || r >= grid1.size() || c >= grid1[0].size()){
            return true;
        }
        if(visited[r][c] == 1 || grid2[r][c] == 0){
            return true;
        }

        visited[r][c] = 1;
        
        
        bool temp_res = traversal(grid1, grid2, r-1,c) & traversal(grid1, grid2, r+1,c) & traversal(grid1, grid2, r,c-1) & traversal(grid1, grid2, r,c+1);
        if(grid1[r][c] == 0){
            return false;
        }
        return temp_res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        for(int i = 0; i < grid2.size(); i++){
            for(int j = 0; j < grid2[0].size(); j++){
                if(visited[i][j] == 0 && grid2[i][j] == 1){
                    // cout << i << " " << j << '\n';
                    if(traversal(grid1, grid2, i, j)){
                        // cout << i << " " << j << '\n';
                        res++;
                    }
                }
            }
        }
        // cout << traversal(grid1, grid2, 1,0) << '\n';
        // for(int i= 0; i < grid1.size(); i++){
        //     for(int j = 0; j < grid1[0].size(); j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        return res;
    }
};