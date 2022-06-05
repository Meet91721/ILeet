class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        for(auto v: redEdges)
            g[v[0]].push_back({v[1],0});
        for(auto v: blueEdges)
            g[v[0]].push_back({v[1],1});
        
        vector<vector<int>>dist(n, vector<int>(2,-1));

        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        dist[0] = {0,0};
        
        while(!q.empty()){
            auto [index, color] = q.front();
            q.pop();
            for(auto [child_index, child_color]: g[index]){
                if(dist[child_index][child_color] != -1 || color == child_color)
                        continue;
                
                dist[child_index][child_color] = 1 + dist[index][color];
                q.push({child_index, child_color});
                
            }
        }
        
        vector<int>res;
        for(auto &it: dist){
            sort(it.begin(), it.end());
            // cout << it[0] << " " << it[1] << '\n';
            if(it[0] == -1)
                res.push_back(it[1]);
            else
                res.push_back(it[0]);
        }
        return res;
        
        
    }
};