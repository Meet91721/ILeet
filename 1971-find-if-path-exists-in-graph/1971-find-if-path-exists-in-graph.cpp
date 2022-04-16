class Solution {
public:
    
    vector<int> graph[1000010];
    
    int visited[1000010] = {0};
    
    bool dfs(int node, int prnt, int to_find){
        if(to_find == node){
            return true;
        }
        bool res = false;
        for(int i = 0; i < graph[node].size(); i++){
            if(visited[graph[node][i]] != 1 && graph[node][i] != prnt){
                visited[graph[node][i]] = 1;
                res = res | dfs(graph[node][i], node, to_find);
            }
            if(res){
                return res;
            }
        }
        return res;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        for(int i = 0; i < edges.size(); i++){
            for(int j = 0; j < edges[i].size(); j++){
                graph[edges[i][0]].push_back(edges[i][1]);
                graph[edges[i][1]].push_back(edges[i][0]);
            }
        }
        visited[source] = 1;
        return dfs(source, source, destination);
    }
};