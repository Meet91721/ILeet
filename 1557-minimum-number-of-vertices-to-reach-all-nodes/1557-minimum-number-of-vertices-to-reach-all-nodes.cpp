class Solution {
public:
    
    /*
    Sometimes I think too much
    void traversal(vector<bool>&vis, vector<vector<int>>&g, int node){
        vis[node] = 1;
        for(auto nodes: g[node]){
            if(vis[nodes])
                continue;
            traversal(vis, g, nodes);
        }
        return;
    }
    */
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        unordered_set<int>s;
        vector<int>res;
        for(int i = 0; i < edges.size(); i++){
            s.insert(edges[i][1]);
        }
        for(int i = 0; i < n; i++){
            if(s.find(i) == s.end()){
                res.push_back(i);
            }
        }
        
        return res;
        
    }
};