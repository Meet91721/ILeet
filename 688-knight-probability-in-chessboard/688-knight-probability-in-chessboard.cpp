class Solution {
public:
    
    vector<pair<int,int>> movements = {
        {2,1},{-2,1},{-2,-1},{2,-1},
        {1,2},{1,-2},{-1,2},{-1,-2}
    };
    
    double dp[26][26][101];
    
    double funcc(int i, int j, int n, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col){
            return 0;
        }
        if(n==0)
            return 1;
        if(dp[i][j][n]!=0)
            return dp[i][j][n];
        double temp = 0;
        for(auto movement: movements){
            temp+=funcc(i+movement.first,j+movement.second,n-1,row,col);
        }
        return dp[i][j][n]=(temp/8);
    }
    
    double knightProbability(int n, int k, int row, int column) {
        // memset(dp,-1,sizeof(dp));
        // for(int i= 0; i < n; i++){
        //     for(int j = 0; j < n; j++)
        //         for(int x = 0; x < k; x++)
        //             cout << dp[i][j][x] << " ";
        // }
        // cout << dp[n-1][][k];
        return funcc(row,column,k,n,n);
    }
};