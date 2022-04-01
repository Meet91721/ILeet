class Solution {
public:
    vector<vector<int>> alll;
    void dfs(int n, vector<int> prnt, int trgt, vector<vector<int>>& graphh){
        prnt.push_back(n);
        if(n == trgt){
            alll.push_back(prnt);
            return;
        }
        for(int i = 0; i < graphh[n].size(); i++){
            vector<int> temp = prnt;
            dfs(graphh[n][i],temp, trgt, graphh);
        }
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, {}, graph.size()-1, graph);
        return alll;
    }
};