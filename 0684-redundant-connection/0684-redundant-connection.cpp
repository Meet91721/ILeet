class Solution {
public:
    int prnt[2000];
    int FIND(int i){
        if(prnt[i] == i)
            return i;
        return prnt[i] = FIND(prnt[i]);
    }
    void UNION(int a, int b){
        a = FIND(a);
        b = FIND(b);
        if(a!=b)
            prnt[a]=b;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i < edges.size()+1; i++)
            prnt[i]=i;
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(FIND(a)==FIND(b))
                return {a,b};
            UNION(a,b);
        }
        return {};
    }
};