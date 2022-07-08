class Solution {
public:
    
    int dp[101][21][101];
    
    int funcc(int i, int lstCol, int neigh, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        
        if(i == m){
            if(neigh == target){
                return 0;
            }
            return INT_MAX/2;
        }
        
        if(dp[i][lstCol][neigh]!=-1)
            return dp[i][lstCol][neigh];
        
        int mx = INT_MAX/2;
        if(houses[i]==0){
            for(int j = 0; j < n; j++){
                mx = min(mx,cost[i][j]+funcc(i+1,j+1,(lstCol==j+1)?neigh:neigh+1,houses,cost,m,n,target));
            }
            
            return dp[i][lstCol][neigh] = mx;
        }
        mx = min(mx,funcc(i+1,houses[i],(houses[i]==lstCol)?neigh:neigh+1,houses,cost,m,n,target));
        return dp[i][lstCol][neigh] = mx;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        return (funcc(0,0,0,houses,cost,m,n,target)==INT_MAX/2)?-1:(funcc(0,0,0,houses,cost,m,n,target));
    }
};