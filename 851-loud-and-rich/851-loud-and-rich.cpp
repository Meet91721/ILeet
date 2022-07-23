class Solution {
public:
    
    int dp[501];
    
    int dfs(int node, vector<vector<int>>&g, vector<int>&quiet){
        if(dp[node]!=-1)
            return dp[node];
        int person=node;
        for(int i = 0; i < g[node].size(); i++){
            int temp = dfs(g[node][i],g,quiet);
            if(quiet[temp]<quiet[person])
                person=temp;
        }
        return dp[node]=person;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>g(quiet.size());
        for(int i = 0; i < richer.size(); i++){
            g[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int>res(quiet.size());
        // vector<int>dp(quiet.size(),0);
        for(int i = 0; i < quiet.size(); i++){
            res[i]=dfs(i,g,quiet);
        }
        return res;
    }
};