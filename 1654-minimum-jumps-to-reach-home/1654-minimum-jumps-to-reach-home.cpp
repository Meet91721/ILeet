class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        sort(forbidden.begin(),forbidden.end());
        
        vector<vector<int>>vis(2, vector<int>(x+6000,-1));
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        vis[0][0] = 0;
        
        while(q.size()){
            int pos = q.front().first;
            int flag = q.front().second;
            q.pop();
            
            if(pos == x)
                return vis[flag][pos];
            
            int forward = pos+a;
            int backward = pos-b;
            
            auto it = lower_bound(forbidden.begin(),forbidden.end(),forward);
            if(forward<x+6000 && (it == forbidden.end() || *it != forward) && vis[0][forward]==-1){
                // cout << "He";
                vis[0][forward] = vis[flag][pos]+1;
                q.push({forward,0});
            }
            it = lower_bound(forbidden.begin(),forbidden.end(), backward);
            if(flag == false && backward>=0 && (it == forbidden.end() || *it != backward) && vis[1][backward] == -1){
                vis[1][backward] = vis[flag][pos]+1;
                q.push({backward,1});
            }
        }
        
        return -1;
        
    }
};