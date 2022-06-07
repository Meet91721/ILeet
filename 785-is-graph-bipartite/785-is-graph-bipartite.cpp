class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(graph.size(), 0);
        while(true){
            int index = 0; 
            for(; index < n; index++){
                if(color[index] == 0){
                    break;
                }
            }
            if(index == n)
                return true;
            queue<int>q;
            q.push(index);
            color[index] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                vector<int>children = graph[node];
                for(int i = 0; i < children.size(); i++){
                    if(color[children[i]] == 0){
                        color[children[i]] = -1 * color[node];
                        q.push(children[i]);
                    }
                    else{
                        if(color[children[i]] == -1*color[node]){
                            continue;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};