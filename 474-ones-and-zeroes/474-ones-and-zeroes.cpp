class Solution {
public:
    
    int dp[601][101][101];
    
    int recurse(int index, int m, int n, vector<vector<int>>&cnts){
        if(index==cnts.size() || (m==0 && n == 0)){
            return 0;
        }
        if(dp[index][m][n]!=-1)
            return dp[index][m][n];
        // Rejecting
        int t = recurse(index+1, m, n, cnts);
        // Selecting
        if(cnts[index][0]<=m && cnts[index][1]<=n){
            t = max(t,1+recurse(index+1,m-cnts[index][0],n-cnts[index][1],cnts));
        }
        return dp[index][m][n] = t;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>cnts;
        for(int i = 0; i < strs.size(); i++){
            int z = 0, o = 0;
            for(int j = 0; j < strs[i].length(); j++){
                if(strs[i][j]=='0')
                    z++;
                else
                    o++;
            }
            cnts.push_back({z,o});
        }
        return recurse(0,m,n,cnts);
    }
};