class Solution {
public:
    
    constexpr static int N = 200;
    
    int visited[N][N];
    
    bool traversal(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || c < 0 || r > grid.size() || c > grid[0].size())
            return true;
        if(visited[r][c] == 1 || grid[r][c] == 1)
            return true;
        if(r == grid.size() - 1 || c == grid[0].size() - 1 || r == 0 || c == 0)
            return false;
        visited[r][c] = 1;
        return traversal(grid, r-1, c) & traversal(grid, r, c-1) & traversal(grid, r, c+1) & traversal(grid, r+1, c);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(visited[i][j] == 0 && grid[i][j] == 0 && traversal(grid, i, j)){
                    res++;
                }
            }
        }
        return res;
    }
};