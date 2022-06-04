class Solution {
public:
    
    int visited[1100];
    
    void dfs(vector<vector<int>>& rooms, int node = 0){
        if(visited[node] == 1)
            return;
        visited[node] = 1;
        for(auto nodes: rooms[node]){
            dfs(rooms, nodes);
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms);
        for(int i = 0; i < rooms.size(); i++){
            if(visited[i] == 0)
                return false;
        }
        return true;
    }
};