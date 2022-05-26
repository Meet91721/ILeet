class Solution {
public:
    constexpr static int N = 100;
    // int max_area = 0;
    int visited[N][N];
    
    int traversal(vector<vector<int>> &grid, int r, int c){
        if(r < 0 || c < 0){
            return 0;
        }
        if(r >= grid.size() || c >= grid[0].size()){
            return 0;
        }
        if(visited[r][c] == 1){
            return 0;
        }
        if(grid[r][c] == 0){
            return 0;
        }
        visited[r][c] = 1;
        
        return traversal(grid, r-1,c) + traversal(grid, r+1,c) +traversal(grid, r,c-1) + traversal(grid, r,c+1) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    if(int temp = traversal(grid, i, j); temp > maxi)
                        maxi = temp;
                }
            }
        }
        return maxi;
    }
};