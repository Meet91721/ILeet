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
        vector<int>indegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>res;
        while(q.size()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(int i = 0;i < g[node].size(); i++){
                if(indegree[g[node][i]])
                    indegree[g[node][i]]--;
                if(indegree[g[node][i]]==0)
                    q.push(g[node][i]);
            }
        }
        return res.size()==numCourses;
    }
};