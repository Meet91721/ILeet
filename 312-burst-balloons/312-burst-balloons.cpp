class Solution {
public:
    int dp[301][301];
    int funcc(int i, int j, vector<int>&nums)
    {
        if(i>j)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        int t = 0;
        for(int ind = i; ind<=j; ind++){
            t = max(t, funcc(i, ind-1, nums) + funcc(ind+1,j,nums) + nums[i-1]*nums[ind]*nums[j+1]);
        }
        return dp[i][j] = t;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return funcc(1, nums.size()-2, nums);
    }
};