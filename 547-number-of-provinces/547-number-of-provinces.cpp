class Solution {
public:
    
    int visited[250];
    
    void dfs(vector<vector<int>>& graph, int node){
        if(visited[node])
            return;
        
        // cout << node << " " << visited[node] << '\t';
        visited[node] = 1;
        // cout << node << " " << visited[node] << '\n';
        for(int i = 0; i < graph[node].size(); i++){
            if(graph[node][i])
                dfs(graph, i);
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(visited[i])
                continue;
            // cout << i << '\n';
            res++;
            dfs(isConnected, i);
        }
        return res;
    }
};