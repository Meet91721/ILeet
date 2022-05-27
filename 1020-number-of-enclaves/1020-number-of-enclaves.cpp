class Solution {
public:
    
    constexpr static int N = 600;
    
    int visited[N][N];
    
    int traversal(vector<vector<int>> &grid, int r, int c){
        // cout << r << " " << c << '\n';
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return 0;
        }
        if(grid[r][c] == 0 || visited[r][c] == 1)
            return 0;
        visited[r][c] = 1;
        
        return 1+traversal(grid, r-1, c)+traversal(grid, r+1, c)+traversal(grid, r, c-1)+traversal(grid, r, c+1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int countt = 0;
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            res+=accumulate(grid[i].begin(), grid[i].end(), 0);
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1){
                    if(visited[i][j] != 1){
                        countt+=traversal(grid, i, j);
                    }
                }
            }
        }
        return res - countt;
    }
};