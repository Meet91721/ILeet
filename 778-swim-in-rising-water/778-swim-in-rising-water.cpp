class Solution {
public:
    
    bool isValid(int r, int c, vector<vector<int>>& grid){
        if(r<0 || c<0 || c>=grid[0].size() || r >= grid.size())
            return false;
        return true;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        // {time, {x,y}}
        set<pair<int,pair<int,int>>>s;
        s.insert({grid[0][0],{0,0}});
        vector<vector<int>> movements = {
            {1,0},{0,1},
            {0,-1},{-1,0}
        };
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        vis[0][0]=1;
        while(s.size()){
            auto [time,cord] = *s.begin();
            auto [x,y] = cord;
            s.erase(s.begin());
            if(x == grid.size()-1 && y == grid[0].size()-1)
                return time;
            for(auto movement: movements){
                int childX = x+movement[0];
                int childY = y+movement[1];
                if(isValid(childX,childY,grid)==false)
                    continue;
                if(vis[childX][childY])
                    continue;
                vis[childX][childY]=1;
                s.insert({max(time,grid[childX][childY]),{childX,childY}});
            }
        }
        return 0;
    }
};