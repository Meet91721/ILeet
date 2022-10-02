class Solution {
public:
    const static int MOD = 1e9+7;
    int dp[31][1001];
    
    long long int fun(int n, int sum, int k){
        if(n == 0){
            if(sum==0)
                return 1;
            return 0;
        }
        int &t = dp[n][sum];
        if(t!=-1)
            return t;
        t=0;
        for(int i = 1; i <= k; i++){
            if(sum-i>=0)
                t=(t+fun(n-1,sum-i,k))%MOD;
            else
                break;
        }
        return t;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return fun(n,target,k);
    }
};