class Solution {
public:
    
    bool dfs(int course, vector<vector<int>>&g, vector<int>&vis){
        vis[course]=1;
        for(int i = 0; i < g[course].size(); i++){
            if(vis[g[course][i]]==1)
                return false;
            if(vis[g[course][i]])
                continue;
            vis[g[course][i]]=1;
            if(dfs(g[course][i],g,vis)==false)
                return false;
        }
        vis[course]=2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            if(vis[i])
                continue;
            if(dfs(i,g,vis)==false)
                return false;
        }
        return true;
    }
};