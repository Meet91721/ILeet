class Solution {
public:
    
    vector<vector<int>> movements = {
        {1,0},{0,1},
        {-1,0},{0,-1}
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();
        set<pair<int,vector<int>>>s;
        s.insert({0,{0,0}});
        
        vector<vector<int>>efforts(m,vector<int>(n,INT_MAX));
        
        while(s.size()){
            
            int effort = (*s.begin()).first;
            
            int x = (*s.begin()).second[0];
            int y = (*s.begin()).second[1];
            
            s.erase(s.begin());
            
            if(x==m-1 && y==n-1)
                return effort;
            if(effort>=efforts[x][y])
                continue;
            
            efforts[x][y]=effort;
            for(auto movement: movements){
                int x_child = x+movement[0];
                int y_child = y+movement[1];
                
                if(x_child<0 || y_child<0 || x_child>=m || y_child>=n)
                    continue;
                
                int child_Efforts=max(effort,abs(heights[x][y]-heights[x_child][y_child]));
                s.insert({child_Efforts,{x_child,y_child}});
            }
        }
        return -1;
    }
};