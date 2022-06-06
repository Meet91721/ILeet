class Solution {
public:
    
    void traversal(vector<bool>&vis, vector<vector<int>>&g, int node){
        vis[node] = 1;
        for(auto nodes: g[node]){
            if(vis[nodes])
                continue;
            traversal(vis, g, nodes);
        }
        return;
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>g(n);
        unordered_set<int>s;
        
        for(int i = 0; i < edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            s.insert(edges[i][1]);
        }
        
        vector<int>res;
        vector<bool>vis(n, false);
        
        for(int i = 0; i < n; i++){
            if(s.find(i) == s.end()){
                traversal(vis, g, i);
                res.push_back(i);
            }
        }
        
        return res;
        
    }
};