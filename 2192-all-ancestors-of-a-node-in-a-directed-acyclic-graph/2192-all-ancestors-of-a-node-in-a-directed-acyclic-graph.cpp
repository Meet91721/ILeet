class Solution {
public:
    
    set<int>v[1001];
    
    set<int> funcc(int node, vector<vector<int>>&g){
        if(v[node].size()){
            set<int>t=v[node];
            t.insert(node);
            return t;
        }
        set<int> res;
        for(int i = 0; i < g[node].size(); i++){
            auto it = funcc(g[node][i],g);
            for(auto ii: it){
                res.insert(ii);
            }
        }
        // sort(res.begin(),res.end());
        v[node]=res;
        res.insert(node);
        return res;
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n+1);
        for(int i = 0; i < edges.size(); i++){
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>res;
        for(int i = 0; i < n; i++){
            if(v[i].size()==0){
                funcc(i,g);
            }
            res.push_back({});
            for(auto t: v[i])
                res.back().push_back(t);
        }
        return res;
    }
};