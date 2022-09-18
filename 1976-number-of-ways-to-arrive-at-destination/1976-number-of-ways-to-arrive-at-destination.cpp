class Solution {
public:
    
    int MOD = 1e9+7;
    
    int dijkstra(int n, vector<vector<pair<int,int>>>& g){
        vector<long long int>dist(n,LONG_MAX);
        vector<int>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        multiset<pair<long long int,int>>ms;
        ms.insert({0,0});
        while(ms.size()){
            auto [dst,node] = *ms.begin();
            ms.erase(ms.begin());
            
            if(dst>dist[node])
                continue;
            
            for(int i = 0; i < g[node].size(); i++){
                if(dist[g[node][i].first] > dist[node]+g[node][i].second){
                    dist[g[node][i].first] = dist[node]+g[node][i].second;
                    ways[g[node][i].first] = ways[node];
                    ms.insert({dist[g[node][i].first],g[node][i].first});
                }
                else if(dist[g[node][i].first] == dist[node]+g[node][i].second){
                    ways[g[node][i].first] = (ways[g[node][i].first]+ways[node])%MOD;
                }
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout << ways[i] << " ";
        return ways[n-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>g(n);
        for(int i = 0; i < roads.size(); i++){
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        return dijkstra(n,g);
    }
};