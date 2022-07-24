class Solution {
public:
    
    bool checkCycle(int node, vector<vector<int>>& g, vector<int>& vis){
        for(int i = 0; i < g[node].size(); i++){
            if(vis[g[node][i]]==0){
                vis[g[node][i]]=1;
                if(checkCycle(g[node][i],g,vis))
                    return true;
            }
            else if(vis[g[node][i]]==1)
                return true;
        }
        vis[node]=2;
        return false;
    }
    
    vector<int>res;
    
    
    //Probably using for the first time ;)
    void topologicalSort(int node, vector<vector<int>>&g, vector<int>&vis){
        for(int i = 0; i < g[node].size(); i++){
            if(vis[g[node][i]])
                continue;
            vis[g[node][i]]=1;
            topologicalSort(g[node][i],g,vis);
        }
        vis[node]=1;
        res.push_back(node);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>g(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>vis(numCourses,0);
        for(int i = 0; i < numCourses; i++){
            
            if(checkCycle(i,g,vis))
                return {};
        }
        
        for(int i = 0; i < numCourses; i++)
            vis[i]=0;
        
        for(int i = 0; i < numCourses; i++){
            if(vis[i])
                continue;
            topologicalSort(i,g,vis);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};