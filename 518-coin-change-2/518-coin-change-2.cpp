class Solution {
public:

    int dp[301][5001];

    int recurse(int amount, vector<int>& coins, int i){
        if(amount == 0)
            return 1;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        
        int temp = 0;
        int ind = i;
        for(; i < coins.size(); i++){
            if(amount - coins[i] < 0)
                continue;
            // cout << amount - coins[i] << '\n';
            temp+=recurse(amount-coins[i],coins,i);
        }
        // cout << "This : " << i << " " << amount << " " << temp << '\n';
        dp[ind][amount]=temp;
        return temp;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return recurse(amount, coins, 0);
        // return t;
    }

};