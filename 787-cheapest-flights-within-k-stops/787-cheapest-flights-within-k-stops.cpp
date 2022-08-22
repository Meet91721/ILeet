class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>g(n);
        for(int i = 0; i < flights.size(); i++){
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        set<pair<int,int>>q,qnext;
        vector<int>dist(n,INT_MAX);
        q.insert({0,src});
        dist[src]=0;
        k++;
        while(q.size() && k--){
            while(q.size()){
                int city = (*q.begin()).second;
                int currDist = (*q.begin()).first;
                q.erase(q.begin());
                for(int i = 0; i < g[city].size(); i++){
                    if(dist[g[city][i].first]<=currDist+g[city][i].second)
                        continue;
                    dist[g[city][i].first] = currDist+g[city][i].second;
                    qnext.insert({dist[g[city][i].first],g[city][i].first});
                }
            }
            swap(q,qnext);
        }
        
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};