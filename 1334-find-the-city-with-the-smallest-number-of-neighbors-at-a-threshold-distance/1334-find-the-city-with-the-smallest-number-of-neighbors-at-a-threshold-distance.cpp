class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX/4));
        for(int i = 0; i < edges.size(); i++){
            dist[edges[i][0]][edges[i][1]]=edges[i][2];
            dist[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        for(int i = 0; i < n; i++)
             dist[i][i]=0;
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        int cities = INT_MAX;
        int ans = n-1;
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j]<=distanceThreshold)
                    c++;
            }
            if(c<=cities){
                cities=c;
                ans=i;
            }
        }
        return ans;
        // vector<vector<int>> dis(n, vector(n, 10001));
        // int res = 0, smallest = n;
        // for (auto& e : edges)
        //     dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        // for (int i = 0; i < n; ++i)
        //     dis[i][i] = 0;
        // for (int k = 0; k < n; ++k)
        //     for (int i = 0; i < n; ++i)
        //         for (int j = 0; j < n; ++j)
        //             dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        // for (int i = 0; i < n; i++) {
        //     int count = 0;
        //     for (int j = 0; j < n; ++j)
        //         if (dis[i][j] <= distanceThreshold)
        //             ++count;
        //     if (count <= smallest) {
        //         res = i;
        //         smallest = count;
        //     }
        // }
        // return res;
    }
};