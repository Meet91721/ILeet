class Solution {
public:
    
    int dp[501][501];
    
    int func(int i, int j, string &t1, string &t2){
        if(i == t1.size())
            return t2.size()-j;
        if(j == t2.size())
            return t1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int &cost = dp[i][j];
        cost = min({1+func(i+1,j,t1,t2),1+func(i,j+1,t1,t2),1+func(i+1,j+1,t1,t2)});
        if(t1[i]==t2[j])
            cost = min(cost,func(i+1,j+1,t1,t2));
        return cost;
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,word1,word2);
    }
};