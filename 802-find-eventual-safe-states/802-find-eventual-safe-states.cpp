class Solution {
public:
    
    map<int,bool> memoize;
    
    bool dfsTraversal(vector<vector<int>> &graph, vector<bool>visited, int node){
        if(visited[node]){
            memoize[node] = true;
            return true;
        }
        
        auto it = memoize.find(node);
        if(it != memoize.end()){
            return memoize[node];
        }
        
        visited[node] = 1;
        bool temp = false;
        for(int i = 0; i < graph[node].size(); i++){
            temp = temp || dfsTraversal(graph, visited, graph[node][i]);
            if(temp){
                memoize[node] = temp;
                return temp;
            }
        }
        
        memoize[node] = temp;
        return temp;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        for(int i = 0; i < graph.size(); i++){
            vector<bool>visited(graph.size(), 0);
            if(dfsTraversal(graph, visited, i))
                continue;
            res.push_back(i);
        }
        return res;
    }
};