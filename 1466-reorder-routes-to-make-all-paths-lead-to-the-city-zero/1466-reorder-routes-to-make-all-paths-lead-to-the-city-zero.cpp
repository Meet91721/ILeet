class Solution {
public:
    constexpr static int N = 100000;
    int res = 0;
    map<int,vector<int>>in, out;
    int visited[N];
    void Traversal(int node){
        auto it = in.find(node);
        if(it!= in.end()){
            for(auto each_node: in[node]){
                if(visited[each_node])
                    continue;
                visited[each_node]=1;
                Traversal(each_node);
            }
        }
        it = out.find(node);
        if(it != out.end()){
            
            for(auto each_node: out[node]){
                if(visited[each_node])
                    continue;
                visited[each_node]=1;
                res++;
                Traversal(each_node);
            }
        }
        
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto it: connections){
            out[it[0]].push_back(it[1]);
            in[it[1]].push_back(it[0]);
        }
        
        visited[0]=1;
        Traversal(0);
        return res;
    }
};

/*
    0->1
    inside of 1, out from 0
    4->0
    inside of 0, out from 4
*/