class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Creating adjacency list
        vector<int>g[n+1];
        for(int i = 0; i < dislikes.size(); i++){
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }
/*
        coloring the graph:
            white-(-1)
            red-(1)
            blue-(0)
*/
        vector<int>color(n+1,-1);
        
        while(true){
            // Bee Aff Ass
            queue<int>q;
            int i = 1;
            for(; i <= n; i++){
                if(color[i] == -1){
                    q.push(i);
                    color[i]=1;
                    break;
                }
            }
            if(i == n + 1)
                return true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                vector<int>children = g[node];
                for(int j = 0; j < children.size(); j++){
                    if(color[children[j]] == -1){
                        color[children[j]] = 1-color[node];
                        q.push(children[j]);
                    }
                    else if(color[children[j]] == 1 - color[node]){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // cout << "HELLO\n";
        return true;
    }
};