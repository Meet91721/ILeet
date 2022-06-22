class Solution {
public:
    
    int dp[210][20005];
    
    bool recurse(int ind, int sum, vector<int>&nums)
    {
        if(ind < 0)
            return false;
        if(sum < 0)
            return false;
        if(sum == 0)
            return true;
        if(dp[ind][sum] != -1)
            return dp[ind][sum];
        bool res = recurse(ind - 1, sum , nums);
        if(res)
            return dp[ind][sum] = res;
        return dp[ind][sum] = recurse(ind - 1, sum - nums[ind], nums);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
            return false;
        memset(dp,-1,sizeof(dp));
        return recurse(nums.size() - 1, sum/2, nums);
    }
};