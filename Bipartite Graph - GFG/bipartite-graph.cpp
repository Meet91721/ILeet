// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    
	    queue<int>q;
	    vector<int>col(n,-1);
	    for(int i = 0; i < n; i++){
	        if(col[i]==-1){
	            col[i]=1;
	            q.push(i);
	            while(q.size()){
	                int node = q.front();
	                q.pop();
	                for(int j = 0; j < adj[node].size(); j++){
	                    if(col[adj[node][j]]==col[node])
	                        return false;
	                   if(col[adj[node][j]]==1-col[node])
	                    continue;
	                   else
	                        {
	                            col[adj[node][j]]=1-col[node];
	                            q.push(adj[node][j]);
	                        }
	                }
	            }
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends