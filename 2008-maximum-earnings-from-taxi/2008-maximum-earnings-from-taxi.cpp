class Solution {
public:
    
    long long int dp[200000];
    
    long long funcc(int index, vector<vector<vector<int>>>&stats, int n){
        if(index>n)
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        long long int t=0;
        for(int i = 0; i < stats[index].size(); i++){
            t = max(t,funcc(stats[index][i][0],stats,n)+stats[index][i][1]);
        }
        t = max(t,funcc(index+1,stats,n));
        return dp[index]=t;
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        memset(dp,-1,sizeof(dp));
        vector<vector<vector<int>>>stats(n+1);
        for(int i = 0; i < rides.size(); i++){
            stats[rides[i][0]].push_back({rides[i][1],rides[i][2]+rides[i][1]-rides[i][0]});
        }
        return funcc(1,stats,n);
    }
};