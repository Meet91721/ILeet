class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& forbidden) {
        vector<vector<int>>g(n);
        for(int i = 0; i < n-1; i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(0);
        int ans = 1;
        sort(forbidden.begin(),forbidden.end());
        vector<int>vis(n,0);
        vis[0] = 1;
        while(q.size()){
            int curr = q.front();
            q.pop();
            for(int i=  0; i < g[curr].size(); i++){
                if(vis[g[curr][i]])
                    continue;
                int next = g[curr][i];
                vis[next]=1;
                auto it = lower_bound(forbidden.begin(),forbidden.end(),next);
                if(it == forbidden.end() || *it != next){
                    q.push(next);
                    ans++;
                }
            }
        }
        return ans;
    }
};