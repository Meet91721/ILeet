class Solution {
public:
    
    vector<vector<int>> movements = {
        {1,0},{-1,0},
        {0,1},{0,-1}
    };
    
    bool isValid(vector<vector<int>>&g, int r, int c){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[0].size())
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q,q1;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        // if(q.size()==0)
        //     return -1;
        int res = 0;
        while(q.size()>0){
            // cout << q.size() << '\n';
            res++;
            while(q.size() > 0){
                auto node = q.front();
                
                int x = node.first;
                int y = node.second;
                // cout << x << " " << y << '\n';
                q.pop();
                for(auto movement: movements){
                    int child_x = x+movement[0];
                    int child_y = y+movement[1];
                    if(!isValid(grid, child_x, child_y))
                        continue;
                    if(grid[child_x][child_y]==1){
                        grid[child_x][child_y]=2;
                        q1.push({child_x,child_y});
                    }
                }
            }
            swap(q,q1);
        }
        bool isThere = false;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==2)
                    isThere=true;
                if(grid[i][j]==1)
                    return -1;
            }
        }
        if(res == 0 && !isThere)
            return 0;
        return res-1;
    }
};