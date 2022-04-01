class Solution {
public:
    // vector<vector<int>> graphh;
    vector<vector<int>> alll;
    void dfs(int n, vector<int> prnt, int trgt, vector<vector<int>>& graphh){
        if(n == trgt){
            prnt.push_back(n);
            alll.push_back(prnt);
            return;
        }
        prnt.push_back(n);
        for(int i = 0; i < graphh[n].size(); i++){
            // if(find(prnt.begin(), prnt.end(), graphh[n][i]) == prnt.end()){
            vector<int> temp = prnt;
            dfs(graphh[n][i],temp, trgt, graphh);
            // }
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // graphh = graph;
        dfs(0, {}, graph.size()-1, graph);
        return alll;
    }
};