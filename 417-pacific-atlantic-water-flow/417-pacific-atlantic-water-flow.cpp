class Solution {
public:
    constexpr static int N = 250;
    
//     int g[N][N];
    
//     bool isValid(int r, int c, vector<vector<int>> &height){
//         if(r < 0 || c <  0 || r >= height.size() || c >= height[0].size())
//             return false;
//         return true;
//     }
    
//     vector<pair<int, int>> movements = {
//         {1,0},{0,1},
//         {-1,0},{0,-1}
//     };
    
    void dfsTraversal(vector<vector<int>> &height, vector<vector<int>>& visited, int r, int c){
        // cout << "HELLL\n";
        // cout << r << " " << c << '\n';
        if(visited[r][c] == 1)
            return;
        
        visited[r][c] = 1;
        
        if((r+1 >= 0 && c >= 0 && r+1 < height.size() && c < height[0].size()) && (height[r][c] <= height[r+1][c])){
            dfsTraversal(height, visited, r+1, c);
        }
        if((r-1 >= 0 && c >= 0 && r-1 < height.size() && c < height[0].size()) && (height[r][c] <= height[r-1][c])){
            dfsTraversal(height, visited, r-1, c);
        }
        if((r >= 0 && c+1 >= 0 && r < height.size() && c+1 < height[0].size()) && (height[r][c] <= height[r][c+1])){
            dfsTraversal(height, visited, r, c+1);
        }
        if((r >= 0 && c-1 >= 0 && r < height.size() && c-1 < height[0].size()) && (height[r][c] <= height[r][c-1])){
            dfsTraversal(height, visited, r, c-1);
        }
        return;
    }
    /*
            DFS approach
    void pacificTraversal(vector<vector<int>> &height, int r, int c){
        if(g[r][c] == 1)
            return;
        g[r][c] = 1;
        for(auto movement: movements){
            int child_r = r+movement.first;
            int child_c = c+movement.second;
            if(!isValid(child_r,child_c,height))
                continue;
            if(height[child_r][child_c] >= height[r][c]){
                pacificTraversal(height, child_r, child_c);
            }
        }
    }
    
    void atlanticTraversal(vector<vector<int>> &height, int r, int c){
        if(g[r][c] == -1)
            return;
        if(g[r][c] == 1){
            g[r][c] = 2;
            // return;
        }
        else if(g[r][c] == 0)
            g[r][c] = -1;
        for(auto movement: movements){
            int child_r = r+movement.first;
            int child_c = c+movement.second;
            if(!isValid(child_r,child_c,height))
                continue;
            if(height[child_r][child_c] >= height[r][c]){
                atlanticTraversal(height, child_r, child_c);
            }
        }
    }
    
    */
    
    
    /*
    void pacificTraversal(vector<vector<int>>&height, int r, int c){
        if(g[r][c] == 1)
            return;
        g[r][c]=1;
        queue<pair<int,int>>q, q1;
        q.push({r,c});
        while(q.size() > 0){
            
            while(q.size() > 0){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for(auto movement: movements){
                    int child_x = movement.first + x;
                    int child_y = movement.second + y;
                    if(!isValid(child_x, child_y, height))
                        continue;
                    if(g[child_x][child_y] == 1)
                        continue;
                    if(height[child_x][child_y]<height[x][y])
                        continue;
                    g[child_x][child_y] = 1;
                    q1.push({child_x, child_y});
                }
            }
            swap(q,q1);
        }
        return;
    }
    
    void atlanticTraversal(vector<vector<int>> &height, int r, int c){
        if(g[r][c] == -1)
            return;
        if(g[r][c] == 1)
            g[r][c] = 2;
        else if(g[r][c] == 0)
            g[r][c] = -1;
        queue<pair<int,int>> q, q1;
        q.push({r, c});
        while(q.size() > 0){
            
            while(q.size() > 0){
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for(auto movement: movements){
                    int child_x = movement.first + x;
                    int child_y = movement.second + y;
                    if(!isValid(child_x, child_y, height))
                        continue;
                    if(g[child_x][child_y] == -1 || g[child_x][child_y] == 2)
                        continue;
                    
                    if(g[child_x][child_y] == 1){
                        g[child_x][child_y] = 2;
                        q1.push({child_x, child_y});
                        continue;
                    }
                    if(height[child_x][child_y]<height[x][y])
                        continue;
                    else if(g[child_x][child_y] == 0)
                        g[child_x][child_y] = -1;
                }
            }
            swap(q,q1);
        }
    }
    */
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific(heights.size(), vector<int> (heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), vector<int> (heights[0].size(), 0));
        
        for(int i = 0; i < heights.size(); i++){
            dfsTraversal(heights, pacific, i,0);
            dfsTraversal(heights, atlantic, i,heights[0].size() - 1);
        }
        for(int i = 0; i < heights[0].size(); i++){
            dfsTraversal(heights, pacific, 0,i);
            dfsTraversal(heights, atlantic, heights.size() - 1, i);            
        }
        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }
        
        return res;
    }
};