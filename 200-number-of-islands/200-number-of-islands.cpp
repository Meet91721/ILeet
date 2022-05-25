class Solution {
public:
    
    constexpr static int N = 300;
    
    int visited[N][N]={0};
    
    void traversal(int r, int c, vector<vector<char>> &grid){
        if(r < 0 || c < 0){
            return;
        }
        if(r >= grid.size() || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] != '1' || visited[r][c] == 1){
            return;
        }
        
        visited[r][c] = 1;
        traversal(r-1,c,grid);
        traversal(r+1,c,grid);
        traversal(r,c-1,grid);
        traversal(r,c+1,grid);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int countt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    cout << i << " " << j << '\n';
                    countt++;
                    traversal(i,j,grid);
                }
            }
        }
        return countt;
    }
};