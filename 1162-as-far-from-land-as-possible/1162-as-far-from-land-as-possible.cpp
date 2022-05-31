class Solution {
public:
/*
    DFS that gave TLE   :')
    void traverse(int r, int c, int dist, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] == 1){
            return;
        }
        if((dist + 1 >= grid[r][c])&&(grid[r][c]!=0))
            return;
        // cout << r << c << '\n';
        grid[r][c] = dist+1;
        traverse(r-1,c,dist+1,grid);
        traverse(r+1,c,dist+1,grid);
        traverse(r,c-1,dist+1,grid);
        traverse(r,c+1,dist+1,grid);
        return;
    }
*/  
    
    vector<pair<int,int>>movements = {
        {1,0},{-1,0},
        {0,-1},{0,1}
    };
    
    bool isValid(int r, int c,vector<vector<int>> grid){
        return r>=0&&c>=0&&r<grid.size()&&c<grid[0].size();
    }
    
    void BFS( vector<vector<int>> &grid, queue<pair<int,int>> &q){
        int cc = 0;
        while(q.size() > 0){
            cc++;
            auto node = q.front();
            q.pop();
            int v_x = node.first;
            int v_y = node.second;
            for(auto &movement: movements){
                // cc++;
                int child_x = v_x+movement.first;
                int child_y = v_y+movement.second;
                if(!isValid(child_x,child_y,grid))
                    continue;
                
                
                if(grid[child_x][child_y]==1 || grid[child_x][child_y] < 1+grid[v_x][v_y] && grid[child_x][child_y]!=0)
                    continue;
                
                grid[child_x][child_y] = 1+grid[v_x][v_y];
                q.push({child_x,child_y});
            }
            // dist++;
        }
    }
    
    
    // int maxDistance(vector<vector<int>>& grid) {
    //     queue<pair<int,int>>q;
    //     for(int i = 0; i < grid.size(); i++){
    //         for(int j  = 0; j < grid[0].size(); j++){
    //             if(grid[i][j] == 1){
    //                 q.push({i,j});
    //                 // grid[i][j] = 0;
    //                 // traverse(i,j,0,grid);
    //                 // BFS(i,j,grid);
    //             }
    //         }
    //     }
    //     BFS(grid,q);
    //     int mx = 0;
    //     for(int i = 0; i < grid.size(); i++){
    //         for(int j = 0; j < grid[0].size(); j++){
    //             // cout << grid[i][j] << " ";
    //             if(grid[i][j] > mx){
    //                 mx = grid[i][j];
    //             }
    //         }
    //         // cout << '\n';
    //     }
    //     if(mx == 0 || mx == 1){
    //         return -1;
    //     }
    //     return mx-1;
    // }
    
    int maxDistance(vector<vector<int>>& g, int steps = 0) {
      queue<pair<int, int>> q, q1;
      for (auto i = 0; i < g.size(); ++i)
        for (auto j = 0; j < g[i].size(); ++j)
          if (g[i][j] == 1)
            q.push({ i - 1, j }), q.push({ i + 1, j }), q.push({ i, j - 1 }), q.push({ i, j + 1 });
      while (!q.empty()) {
        ++steps;
        while (!q.empty()) {
          int i = q.front().first, j = q.front().second;
          q.pop();
          if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
            g[i][j] = steps;
            q1.push({ i - 1, j }), q1.push({ i + 1, j }), q1.push({ i, j - 1 }), q1.push({ i, j + 1 });
          }
        }
        swap(q1, q);
      }
      return steps == 1 ? -1 : steps - 1;
    }
};