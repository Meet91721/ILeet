class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>>distance(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        set<tuple<int,int,int>>sp;
        sp.insert({0,0,0});
        distance[0][0] = -1;
        auto isValid = [&](int x, int y){
            if(x < grid.size() && y < grid[0].size() && x>=0 && y>=0)
                return true;
            return false;
        };
        
        auto insertElem = [&](int child_x, int child_y, int x, int y, int i, int d){
            if(grid[x][y] == i){
                if(distance[child_x][child_y] > d){
                    sp.insert({d,child_x,child_y});
                }
            }
            else if(distance[child_x][child_y] > d+1){
                sp.insert({d+1,child_x,child_y});
            }
            return;
        };
        
        while(sp.size()){
            auto [d,x,y] = *sp.begin();
            sp.erase(sp.begin());
            distance[x][y] = d;
            if(x == grid.size()-1 && y == grid[0].size()-1)
                return d;
            int child_x = x, child_y = y+1;
            if(isValid(child_x,child_y)){
                insertElem(child_x,child_y,x,y,1,d);
            }
            child_x = x, child_y = y-1;
            if(isValid(child_x,child_y)){
                insertElem(child_x,child_y,x,y,2,d);
            }
            child_x = x+1, child_y = y;
            if(isValid(child_x,child_y)){
                insertElem(child_x,child_y,x,y,3,d);
            }
            child_x = x-1, child_y = y;
            if(isValid(child_x,child_y)){
                insertElem(child_x,child_y,x,y,4,d);
            }
        }
        return 0;
    }
};