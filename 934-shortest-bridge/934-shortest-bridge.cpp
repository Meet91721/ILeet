class Solution {
public:
    
    vector<pair<int,int>> movements = {
        {1,0},{-1,0},
        {0,1},{0,-1}
    };
    
    bool isValid(int r, int c, vector<vector<int>> &mat){
        if(r < 0 || c < 0 || r >= mat.size() || c >= mat[0].size())
            return false;
        return true;
    }
    
    void paint(vector<vector<int>> &grid, int r, int c){
        // dfs to paint
        if(!isValid(r, c, grid))
            return;
        if(grid[r][c] == 1){
            grid[r][c] = 2;
            for(auto movement: movements){
                paint(grid, r+movement.first, c+movement.second);
            }
        }
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        bool isPainted = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    paint(grid,i,j);
                    isPainted = true;
                    break;
                }
            }
            if(isPainted)
                break;
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        // for(int i= 0; i < grid.size(); i++){
        //     for(int j = 0; j < grid[0].size(); j++){
        //         cout << grid[i][j] << "\t\n"[j==grid[0].size() - 1];
        //     }
        // }
        // BFS
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(auto movement: movements){
                int child_x = x + movement.first;
                int child_y = y + movement.second;
                if(!isValid(child_x, child_y, grid))
                    continue;
                
                if(grid[child_x][child_y] == 1){
                    // for(int i= 0; i < grid.size(); i++){
                    //     for(int j = 0; j < grid[0].size(); j++){
                    //         cout << grid[i][j] << "\t\n"[j==grid[0].size() - 1];
                    //     }
                    // }
                    return grid[x][y] - 2;
                }
                    // return grid[x][y] - 1;
                if(grid[child_x][child_y] >= 2)
                    continue;
                // cout << child_x << " " << child_y  << " " << x << " " << y << '\n';
                grid[child_x][child_y] = grid[x][y] + 1;
                q.push({child_x, child_y});
            }
        }
        
//         for(int i= 0; i < grid.size(); i++){
//             for(int j = 0; j < grid[0].size(); j++){
//                 cout << grid[i][j] << "\t\n"[j==grid[0].size() - 1];
//             }
//         }
        return 0;
    }
};


/*
    0 1
    1 0
    
    0   1   0
    0   0   0
    0   0   1
    
*/