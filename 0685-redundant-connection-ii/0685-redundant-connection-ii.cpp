class Solution {
public:
    
    vector<int>res;
    
    bool func(int node, vector<vector<int>>&g ,vector<int>&vis){
        vis[node] = 1;
        for(int i = 0; i < g[node].size(); i++){
            if(vis[g[node][i]]==1){
                res = {node,g[node][i]};
                return true;
            }
            if(vis[g[node][i]]==2)
                continue;
            vis[g[node][i]]=1;
            if(func(g[node][i],g,vis))
                return true;
        }
        vis[node]=2;
        return false;
    }
    int nnn;
    set<vector<int>>p;
    bool findCycle(int node, vector<vector<int>>&g, vector<int>&vis){
        vis[node] = 1;
        // cout << node << '\n';
        for(int i = 0; i < g[node].size(); i++){
            if(vis[g[node][i]] == 2)
                continue;
            if(vis[g[node][i]]){
                nnn=g[node][i];
                p.insert({node,g[node][i]});
                return true;
            }
            vis[g[node][i]]=1;
            if(findCycle(g[node][i],g,vis)){
                p.insert({node,g[node][i]});
                if(node == nnn){
                    return false;
                }
                return true;
            }
        }
        vis[node]=2;
        return false;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>g(n+1);
        vector<int>vis(n+1,0);
        
        vector<vector<int>>ret;
        
        for(int i = 0; i < n; i++){
            if(vis[edges[i][1]]){
                ret.push_back({vis[edges[i][1]],edges[i][1]});
                ret.push_back({edges[i][0],edges[i][1]});
            }
            vis[edges[i][1]]=edges[i][0];
            g[edges[i][0]].push_back(edges[i][1]);
        }
        vis = vector<int>(n+1,0);
        
        // root dont have cycle
        if(ret.size()){
            if(func(ret[0][1],g,vis))
                return res;
            else{
                return ret[1];
            }
        }
        vis=vector<int>(n+1,0);
        for(int i = 1; i < n+1; i++){
            if(vis[i])
                continue;
            findCycle(i,g,vis);
            if(p.size()){
                // cout << i << '\n';
                // cout << "SA";
                // for(auto s: p){
                //     cout << s[0] << " " << s[1] << '\n';
                // }
                for(int j = edges.size()-1; j>=0; j--){
                    if(p.find(edges[j])!=p.end())
                        return edges[j];
                }
            }
        }
        
        
        return res;
    }
};