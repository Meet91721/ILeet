class Solution {
public:
    
    bool isValid(int i, int j, vector<vector<int>>&grid){
        if(i >= grid.size()  || j >= grid[0].size() || i < 0 || j < 0)
            return false;
        return true;
    }
    
    int dp[201][201];
    
    int recurse(int i,int j, vector<vector<int>>&grid){
        if(!isValid(i,j,grid))
            return INT_MAX;
        if(i == grid.size()-1 && j == grid[0].size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int t = min(recurse(i+1,j,grid), recurse(i,j+1,grid))+grid[i][j];
        return dp[i][j] = t;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return recurse(0,0,grid);
    }
};