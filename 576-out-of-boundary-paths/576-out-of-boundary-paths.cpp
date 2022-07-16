class Solution {
public:
    
    int dp[51][51][51];
    
    const int mod = 1e9+7;
    
    int funcc(int i, int j, int n, int rows, int cols){
        
        if(i==rows || j==cols || i==-1 || j==-1)
            return 1;
        if(n==0)
            return 0;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        int t = 0;
        t=(t+funcc(i+1,j,n-1,rows,cols))%mod;
        t=(t+funcc(i-1,j,n-1,rows,cols))%mod;
        t=(t+funcc(i,j+1,n-1,rows,cols))%mod;
        t=(t+funcc(i,j-1,n-1,rows,cols))%mod;
        return dp[i][j][n]=t;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return funcc(startRow,startColumn,maxMove,m,n);
    }
};