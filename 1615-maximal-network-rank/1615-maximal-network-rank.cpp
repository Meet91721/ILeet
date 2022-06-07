class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_set<int>g[n];
        for(int i = 0; i < roads.size(); i++){
            g[roads[i][0]].insert(roads[i][1]);
            g[roads[i][1]].insert(roads[i][0]);
        }
        
        int res = 0;
        map<int,vector<int>, greater<int>>mp;
        for(int i = 0; i < n; i++){
            mp[g[i].size()].push_back(i);
        }
        
        auto it = mp.begin();
        
        vector<int>v1 = it->second;
        bool done = false;
        if(v1.size() > 1){
            for(int i = 0; i < v1.size(); i++){
                for(int j = i + 1; j < v1.size(); j++){
                    int city1 = v1[i];
                    int city2 = v1[j];
                    // cout << city1 << " " << city2 << '\n';
                    if(g[city1].find(city2) != g[city1].end()){
                        res = 2 * g[city2].size() - 1;
                    }
                    else{
                        // cout << city1 << " " << city2 << '\n';
                        return 2 * g[city1].size();
                        
                    }
                }
            }
        }
        else{
            int city1 = v1[0];
            // cout << city1 << '\n';
            it++;
            vector<int>v2 = it->second;
            for(int i = 0; i < v2.size(); i++){
                int city2 = v2[i];
                // cout << city2 << '\n';
                if(g[city1].find(city2) == g[city1].end())
                {
                    return g[city1].size() + g[city2].size();
                    
                }
                else{
                    res = g[city1].size() + g[city2].size() - 1;
                }
            }
        }
        return res;
        
    }
};