class Solution {
public:
    
    int mx = 0;
    constexpr static int N = 100100;
    vector<int>g[N];
    
    void dfsTraversal(int employee, int time, vector<int>&informTime){
        if(time+informTime[employee] > mx){
            mx = time+informTime[employee];
        }
        time += informTime[employee];
        for(auto emp: g[employee]){
            dfsTraversal(emp, time, informTime);
        }
        return;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] == -1)
                continue;
            g[manager[i]].push_back(i);
        }
        
        dfsTraversal(headID, 0, informTime);
        
        /*
        int time = 0;
        queue<int>q, q1;
        q.push(headID);
        
        while(!q.empty()){
            // cout << q.front() << '\n';
            time+=informTime[q.front()];
            while(!q.empty()){
                int employee = q.front();
                q.pop();
                for(auto employees: g[employee])
                    q1.push(employees);
            }
            swap(q,q1);
        }
        */
        return mx;
        
    }
};