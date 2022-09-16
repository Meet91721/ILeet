class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        set<tuple<int,int,int>>visited;
        queue<tuple<int,int,int>>q;
        int steps = 0;
        vector<pair<int,int>> movements = {
            {1,0},{0,1},
            {-1,0},{0,-1}
        };
        auto isValid = [&](int i, int j){
            if(i == grid.size() || j == grid[0].size() || i<0 || j<0)
                return false;
            return true;
        };
        q.push({0,0,k});
        while(q.size()){
            int sze = q.size();
            while(sze--){
                auto [i,j,temp_k] = q.front();
                if(i == grid.size()-1 && j == grid[0].size()-1){
                    return steps;
                }
                q.pop();
                for(auto movement: movements){
                    int child_i = i+movement.first;
                    int child_j = j+movement.second;
                    if(isValid(child_i,child_j) == false)
                        continue;
                    
                    if(grid[child_i][child_j]){
                        if(visited.find({child_i,child_j,temp_k-1})==visited.end() && temp_k){
                            visited.insert({child_i,child_j,temp_k-1});
                            q.push({child_i,child_j,temp_k-1});
                        }
                    }
                    else{
                        if(visited.find({child_i,child_j,temp_k})==visited.end()){
                            visited.insert({child_i,child_j,temp_k});
                            q.push({child_i,child_j,temp_k});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};