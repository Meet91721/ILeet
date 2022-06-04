class Solution {
public:
    
    bool isValid(vector<vector<int>>&grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        
        if(grid.size() == 1 && grid[0].size() == 1)
            return 1;
        
        
        grid[0][0] = 1;
        queue<pair<int,int>> q;
        vector<pair<int,int>> movements = {
            {-1,-1}, {1,1},
            {-1,0}, {1, 0},
            {0,1}, {0, -1},
            {-1,1}, {1, -1}
        };
        q.push({0, 0});
        while(q.size() > 0){
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            
            for(auto movement: movements){
                int child_x = x + movement.first;
                int child_y = y + movement.second;
                
                if(!isValid(grid, child_x, child_y))
                    continue;
                
                if(grid[child_x][child_y] != 0)
                    continue;
                
                grid[child_x][child_y] = 1+grid[x][y];
                if(child_x == grid.size() - 1 && child_y == grid[0].size() - 1)
                    return grid[child_x][child_y];
                q.push({child_x, child_y});
                
            }
        }
        return -1;
    }
};