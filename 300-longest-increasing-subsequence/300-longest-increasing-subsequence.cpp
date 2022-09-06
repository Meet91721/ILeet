class Solution {
public:
    
    int dp[2501][3000];
    
    int funcc(int n, vector<int>& nums, int lst){
        if(nums.size() == n)
            return 0;
        int ttt = lst;
        if(ttt==-1)
            ttt=2999-1;
        if(dp[n][ttt]!=-1)
            return dp[n][ttt];
        int res = funcc(n+1,nums,lst);
        if(lst == -1 || nums[lst] < nums[n])
            res = max(res, 1+funcc(n+1,nums,n));
        return dp[n][ttt]=res;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return funcc(0,nums,-1);
    }
};