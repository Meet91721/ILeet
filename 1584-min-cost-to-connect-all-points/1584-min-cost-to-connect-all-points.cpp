class Solution {
public:
    
    // Applying kruskal
    int parent[1001];
    
    int Find(int a){
        if(parent[a] == a)
            return a;
        return parent[a] = Find(parent[a]);
    }
    
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        parent[b] = a;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>>edges;
        for(int i = 0; i < points.size(); i++)
            parent[i] = i;
        for(int i = 0; i < points.size(); i++)
            for(int j = 0; j < points.size(); j++)
                if(i!=j)
                    edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
        make_heap(edges.begin(),edges.end(),greater<tuple<int,int,int>>());
        int connected = 0;
        int res = 0;
        while(edges.size() && 1+connected<points.size()){
            pop_heap(edges.begin(),edges.end(),greater<tuple<int,int,int>>());
            auto [wt,i,j] = edges.back();
            edges.pop_back();
            i = Find(i);
            j = Find(j);
            if(i!=j){
                connected++;
                Union(i,j);
                res+=wt;
            }
        }
        return res;
    }
};